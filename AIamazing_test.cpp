#include <iostream>
#include <tins/tins.h>
#include <fstream>
#include <iomanip> 

using namespace Tins;
using namespace std;
std::ofstream outfile;


//when sniff packet, into this callback//
bool callback(const PDU &pdu) {
    // Find the IP layer
    const IP &ip = pdu.rfind_pdu<IP>(); 
    // Find the TCP layer
    const TCP &tcp = pdu.rfind_pdu<TCP>(); 
     cout << ip.src_addr() << ':' << tcp.sport() << " -> "
 		  << ip.dst_addr() << ':' << tcp.dport() << endl;

    // Extract the RawPDU object.
    const RawPDU& raw = tcp.rfind_pdu<RawPDU>();
    // Finally, take the payload (this is a vector<uint8_t>)
    const RawPDU::payload_type& payload = raw.payload();  

   //get TCP raw data, only payload
    std::string message( payload.begin(), payload.end() ); 
    std::cout << std::hex << message << std::endl;
    

   //write to file
   outfile << std::hex << message << endl;

 return true;

}

int main() {
   
    outfile.open("sniffer.dat");

	SnifferConfiguration config;
	//config.set_filter("port 50");
	config.set_promisc_mode(true);

	Sniffer sniffer("lo", config);
    sniffer.sniff_loop(callback);

	outfile.close();
    
   return 0;


}
