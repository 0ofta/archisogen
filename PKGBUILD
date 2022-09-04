# Maintainer: Kaare Jenssen <kaare at jenssen dot it>

pkgname='archisogen'
pkgver=0.1.0
pkgrel=1
pkgdesc='Simple program to ease the creation of Arch live ISO files'
arch=('x86_64')
url='https://github.com/0ofta/archisogen.git'
license=('GPL2')
depends=('archiso')
makedepends=('git')
provides=('archisogen')
source=($pkgname::git+https://github.com/0ofta/archisogen)
md5sums=('SKIP')

build() {
  cd $pkgname
  make
}

package() {
  cd $pkgname
  install -Dm755 archisogen "$pkgdir"/usr/bin/archisogen

  install -d "$pkgdir"/root/archlive/airootfs/root

  install -D /usr/share/archiso/configs/releng/packages.* "$pkgdir"/root/archlive/
  install -D /usr/share/archiso/configs/releng/pacman.conf "$pkgdir"/root/archlive/
  install -D /usr/share/archiso/configs/releng/airootfs/root/customize_airootfs.sh "$pkgdir"/root/archlive/airootfs/root/
  install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/archisogen/LICENSE
}

# vim:set ts=2 sw=2 et:
