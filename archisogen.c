#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <errno.h>

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
	printf("\nCopying base files...");
	sprintf(dummy, "cp -r %s %s", precmd, argv[1]);
	system(dummy);
	
	/* copy custom files into base files */
	printf("\nCopying custom files to base...");
	sprintf(toodummy, "cp -r /root/archlive/* %s", argv[1]);
	system(toodummy);	

	/* Check if new directory exist */
	DIR* dir = opendir(argv[1]);
	if (dir) {
		/* directory exist */
		printf("\nMaking build folder [SUCCESS]\n\nGo to %s and run ./build.sh -v to build your ISO file.", argv[1]);
		closedir(dir);
	} else if (ENOENT == errno) {
		/* directory does not exist */
		printf("\nMaking build folder [FAILED]\n");
	} else {
		/* opendir() failed for some reason */
	printf("Unknown error - could not check build status.\nPlease Check if your folder was created/populated.\nThis proparby means your build folder was not created successfully!\n");
	}
	return 0;
}
