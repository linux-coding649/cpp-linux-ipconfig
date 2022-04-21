#include <iostream>

using namespace std;

int main() {
cout << "Debian Linux IPCONFIG" << endl;
string task;
cout << "Task [listaddress|listinterfaces|listall|renew|flush|ipaddradd]:";
cin >> task;
if (task == "listall") {
cout << "Linux IP Address Configuraton:"<< endl;
system("ip addr sh");
cout << endl;
cout << "Linux Network Interface Configuration:" << endl;
system("ifconfig");
cout << endl;
cout << "END OF IPCONFIG" << endl;
return 0;}
else if (task == "listaddress") {
cout << "Linux IP Address Configuration:" << endl;
system("ip addr sh");
cout << "END OF IPCONFIG" << endl;
return 0;}
else if (task == "listinterfaces") {
cout << "Linux Network Interface Configuration:" << endl;
system("ifconfig");
cout << "END OF IPCONFIG" << endl;
return 0;}
else if (task == "renew") {
string ip;
string vbose;
cout << "Which IP Version [ipv4|ipv6]:";
cin >> ip;
if (ip == "ipv4") {
cout << "Allow verbose output [y|n]:";
cin >> vbose;
if (vbose == "y") {
string iface;
cout << "Interface:";
cin >> iface;
string cmd = "sudo dhclient -4 -v " + iface;
system(cmd.c_str());
return 0;
}
else if (vbose == "n") {
string iface;
cout << "Interface:";
cin >> iface;
string cmd = "sudo dhclient -4 "+iface;
system(cmd.c_str());
return 0;
}
else {
cout << "Unknown Task. If you think you recieved this message because of a bug, e-mail the maintainer to fix it. You may also ask for source code and fix it." << endl;
return 0;
}
}
else if (ip == "ipv6") {
cout << "Allow verbose output [y|n]:";
cin >> vbose;
if (vbose == "y") {
string iface;
cout << "Interface:";
cin >> iface;
string cmd = "sudo dhclient -6 -v " + iface;
system(cmd.c_str());
return 0;
}
else if (vbose == "n") {
string iface;
cout << "Interface:";
cin >> iface;
string cmd = "sudo dhclient -6 " + iface;
system(cmd.c_str());
return 0;
}
else {
cout << "Unknown Task. If you think you recieved this message because of a bug, e-mail the maintainer to fix it. You may also ask for source code and fix it." << endl;
return 0;
}
}
else {
cout << "Unknown Task. If you think you recieved this message because of a bug, e-mail the maintainer to fix it. You may also ask for source code and fix it." << endl;
return 0;
}
}
else if (task == "flush") {
string iface;
cout << "Interface:";
cin >> iface;
string cmd = "sudo ip addr flush dev " + iface;
system(cmd.c_str());
return 0;
}
else if (task == "ipaddradd") {
string ipaddr;
string iface;
cout << "IP Address (write like:[x.x.x.x/xx]):";
cin >> ipaddr;
cout << "Interface:";
cin >> iface;
string cmd = "sudo ip address add "+ipaddr+" dev "+iface;
system(cmd.c_str());
return 0;

}else {
cout << "Unknown Task. If you think you recieved this message because of a bug, e-mail the maintainer to fix it. You may also ask for source code and fix it." << endl;
return 0;
}
}

