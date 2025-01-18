LINUX_TOOLCHAIN_PATH = /home/autobuild/tools/win32

PathTozlib = contrib/sdk/sources/zlib

install libz.a libz.dll clean:
	$(MAKE) -C $(PathTozlib) $@



kos-zlib-dev: libz.a libz.dll
	mkdir -p $@$(LINUX_TOOLCHAIN_PATH)/include
	mkdir -p $@$(LINUX_TOOLCHAIN_PATH)/mingw32/lib

	cp -f $(PathTozlib)/*.h $@$(LINUX_TOOLCHAIN_PATH)/include
	cp -f $(PathTozlib)/*.a $@$(LINUX_TOOLCHAIN_PATH)/mingw32/lib

	dpkg-deb --build $@ $@.deb
