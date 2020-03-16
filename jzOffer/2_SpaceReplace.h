#include <cstring>

class Solution {
public:
	void replaceSpace(char *str,int length) {
        int len = 0, spaces = 0;
        while(str[len] != '\0'){
            if(str[len] == ' ') spaces++;
            len++;
        }
        for(int i = len; i >= 0; i--){
            if(str[i] != ' ') str[i + 2 * spaces] = str[i];
            else{
                str[i + 2 * spaces - 2] = '%';
                str[i + 2 * spaces - 1] = '2';
                str[i + 2 * spaces] = '0'; 
                spaces--;
            }
        }
	}
};