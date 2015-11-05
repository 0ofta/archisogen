/* adds /root/archisoconfig folder and copies normally edited files and folders */
#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("sudo pacman -Syu --noconfirm");
	system("sudo pacman -S archiso --noconfirm");

	system("sudo mkdir -p /root/archisoconfig/airootfs/root");

	system("sudo cp /usr/share/archiso/configs/releng/packages.* /root/archisoconfig");
	system("sudo cp /usr/share/archiso/configs/releng/pacman.conf /root/archisoconfig");
	system("sudo cp /usr/share/archiso/configs/releng/airootfs/root/customize_airootfs.sh /root/archisoconfig/airootfs/root/customize_airootfs.sh");
	
	system("sudo chmod +x archisogen");
	system("sudo cp archisogen /usr/bin");

	printf("\n\nCreated base configuration files in /root/archisoconfig - remember to always edit these files as root!\n");
	printf("When you are satisfied with the content of archisoconfig, move to /root/ and run archisogen <destination> to create a build folder.\n");
	printf("\nThen enter <destination> folder, and run ./build -v to create the actual ISO file. The ISO will be located in <destination>/out/ISO-file.iso\n");

	return 0;
}
