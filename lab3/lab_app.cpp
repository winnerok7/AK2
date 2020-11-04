#include <stdio.h>
#include <unistd.h>
#include <map>
#include <string>
#include <getopt.h>

using namespace std;

int main(int argc, char *argv[]){
    int cmd_str = 0;
	map <string, bool> str;

	int index = -1;
	//h-help, l-list, v-version, V-value
	const char* short_str = "hlvV::?";


	const struct option long_str[] = {
        {"help",0,NULL,'h'},
        {"list",0,NULL,'l'},
        {"version",0,NULL,'v'},
		{"value",0,NULL,'V'},
        {NULL,0,NULL,0},
    };

	while ((cmd_str = getopt_long(argc,argv,short_str,long_str, &index)) != -1){
		switch (cmd_str){
		case 'h': {
			if (str["h"] == false) {
				printf("Arg: Help\n");
				str["h"] = true;
				break;
			}
			break;
		}
		case 'l': {
			if (str["l"] == false) {
				printf("Arg: List\n");
				str["l"] = true;
				break;
			}
			break;
		}
		case 'v': {
			if (str["v"] == false) {
				printf("Arg: version\n");
				str["v"] = true;
				break;
			}
			break;
		}
		case 'V': {
			if (str["V"] == false) {
				if (optarg == NULL) {
					printf("Arg: value\n");
					str["V"] = true;
				}else {
				printf("Arg: Value %s\n", optarg);
				used["V"] = true;
			}
				break;
			}
			break;
		}

		case '?': default: {
			printf("Error:Key %c is not found.\n", cmd_str);
			break;
			}
        };
		index = -1;
	};
};
