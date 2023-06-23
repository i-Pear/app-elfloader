gcc $APPELFLOADER_BASE/vdso/vdso.c -c -o $APPELFLOADER_BASE/vdso/libvdso.o -fPIC -O2 -nostdlib
while IFS=' ' read -r vdso_symbol _; do
  objcopy --add-symbol $vdso_symbol=.text:$VDSO_MAGIC_NUMBER,global,function $APPELFLOADER_BASE/vdso/libvdso.o
  ((VDSO_MAGIC_NUMBER++))
done < $APPELFLOADER_BASE/vdso/vdso_mapping.conf
ld $APPELFLOADER_BASE/vdso/libvdso.o -o $APPELFLOADER_BASE/vdso/libvdso.so --hash-style=both -soname unikraft-vdso.so.1 -shared -T $APPELFLOADER_BASE/vdso/vdso.lds
python3 $APPELFLOADER_BASE/vdso/bin2c.py $APPELFLOADER_BASE/vdso/vdso_mapping.conf $APPELFLOADER_BASE/vdso/libvdso.so $APPELFLOADER_BASE/vdso/vdso-image.c
