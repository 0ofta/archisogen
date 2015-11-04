/* adds /root/archisoconfig folder and copies normally edited files and folders */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("sudo pacman -Syu");
	system("sudo pacman -S archiso");

	system("sudo su");

	system("mkdir /root/archisoconfig");
	system("cp /usr/share/archiso/configs/releng/packages.both /root/archisoconfig");
	system("cp /usr/share/archiso/configs/releng/packages.x86_64 /root/archisoconfig");
	system("cp /usr/share/archiso/configs/releng/packages.i686 /root/archisoconfig");
	system("cp /usr/share/archiso/configs/releng/pacman.conf");
	
	system("mkdir /root/archisoconfig/airootfs");
	system("mkdir /root/archisoconfig/airootfs/home");
	
	system("mkdir /root/archisoconfig/airootfs/root");
	system("cp /usr/share/archiso/configs/releng/airootfs/root/customize_airootfs.sh /root/archisoconfig/airootfs/root/customize_airootfs.sh");
	
	system("mkdir /root/archisoconfig/airootfs/etc");

	system("chmod +x archisogen");
	system("cp archisogen /usr/bin");

	system("clear");
	printf("\n\nCreated base configuration files in /root/archisoconfig - remember to always edit these files as root!\n");
	printf("When you are satisfied with the content of archisoconfig, move to /root/ and run archisogen <destination> to create a build folder.\n");
	printf("\nThen enter <destination> folder, and run ./build -v to create the actual ISO file. The ISO will be located in <destination>/out/ISO-file.iso\n");

	return 0;
}
