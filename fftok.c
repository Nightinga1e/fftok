#include <stdio.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>

int main()
{
	key_t ipckey;
	int msg_id;
	char *path = "/os5_2";
	int id = 'A';
	struct{
		long type;
		char text[100];
	}mymsg;
	ipckey = ftok(path,id);
	printf("KEY IS %d\n", ipckey);
	msg_id = msgget(ipckey, IPC_CREAT | 0666);
	printf("Message id is %d\n", msg_id);

	memset(mymsg.text, 0, 100);
	strcpy(mymsg.text, "SURPRISE MOTHERQUACKER");
	mymsg.type=1;
	msgsnd(msg_id,&mymsg,sizeof(mymsg),0);

	return 0;
}
