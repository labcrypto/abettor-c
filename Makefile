#  The MIT License (MIT)
#
#  Copyright (c) 2015 LabCrypto Org.
#
#  Permission is hereby granted, free of charge, to any person obtaining a copy
#  of this software and associated documentation files (the "Software"), to deal
#  in the Software without restriction, including without limitation the rights
#  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
#  copies of the Software, and to permit persons to whom the Software is
#  furnished to do so, subject to the following conditions:
#  
#  The above copyright notice and this permission notice shall be included in all
#  copies or substantial portions of the Software.
#  
#  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
#  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
#  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
#  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
#  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
#  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
#  SOFTWARE.
#

all:
	make -C bio
	make -C crypto
	make -C date
	make -C log
	make -C fs
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
	make -C fs install
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
	make -C fs clean
	make -C pkcs11 clean
	make -C rand clean
	make -C scard clean
	make -C test clean
	make -C unicode clean
	make -C util clean
