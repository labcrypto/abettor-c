all:
	make -C bio
	make -C crypto
	make -C date
	make -C log
	make -C os
	make -C pkcs11
	make -C rand
	make -C scard
	make -C test
	make -C unicode
	make -C util

install:
	make -C bio install
	make -C crypto install
	make -C date install
	make -C log install
	make -C os install
	make -C pkcs11 install
	make -C rand install
	make -C scard install
	make -C test install
	make -C unicode install
	make -C util install

clean:
	make -C bio clean
	make -C crypto clean
	make -C date clean
	make -C log clean
	make -C os clean
	make -C pkcs11 clean
	make -C rand clean
	make -C scard clean
	make -C test clean
	make -C unicode clean
	make -C util clean