#include <sys/types.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>

int main(){
	key_t ipckey;
	char *path = "/os5_2";
	int id = 'A';
	int msg_id;
	struct{
		long type;
		char text[100];
	}mymsg;
	int receive;
	ipckey=ftok(path,id);
	printf("My key is %d\n", ipckey);
	msg_id = msgget(ipckey, 0);
	printf(" Message id is %d\n", msg_id);
	receive = msgrcv(msg_id, &mymsg, sizeof(mymsg),0,0);
	printf("%s (%d) \n", mymsg.text, receive);
	return 0;
}
