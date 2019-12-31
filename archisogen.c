#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	/* error handling */
	if (argc < 2) {
		printf("\nUSAGE: archisogen <destination>\n\nhttps://github.com/kaarejens/archisogen for more detailed information.\n");
		return 1;
	}
	
	char dummy[100];
	char toodummy[100];
	char precmd[] = "/usr/share/archiso/configs/releng ";

	/* copy base files */
	sprintf(dummy, "cp -r %s %s", precmd, argv[1]);
	system(dummy);
	
	/* copy your custom files into base files */
	sprintf(toodummy, "cp -r /root/archlive/* %s", argv[1]);
	system(toodummy);	

	printf("\n\nDone. Go to argv[1] to build ISO file.\n");
	return 0;
	
}
