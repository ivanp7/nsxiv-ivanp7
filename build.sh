#!/bin/sh

cd -- "$(dirname -- "$0")"

DIR="$PWD"

git clone "https://aur.archlinux.org/nsxiv.git" nsxiv && cd nsxiv || exit 1
sed -i 's/^pkgname=.*$/pkgname=nsxiv-ivanp7/' PKGBUILD
sed -i 's/^source=("\$pkgname/source=("$_pkgname/' PKGBUILD
echo "provides=('nsxiv')" >> PKGBUILD
makepkg --noconfirm -o

cd src/nsxiv/

install -m 644 -t . "$DIR/config.h" "$DIR/nsxiv.1" "$DIR/keycodes.patch"
patch < keycodes.patch

cd ../..

makepkg --noconfirm -efsr && mv *.pkg.tar.zst ../

