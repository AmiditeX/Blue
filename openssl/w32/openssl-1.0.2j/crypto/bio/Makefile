#
# OpenSSL/crypto/bio/Makefile
#

DIR=	bio
TOP=	../..
CC=	cc
INCLUDES= -I.. -I$(TOP) -I../../include
CFLAG=-g
MAKEFILE=	Makefile
AR=		ar r

CFLAGS= $(INCLUDES) $(CFLAG)

GENERAL=Makefile
TEST=
APPS=

LIB=$(TOP)/libcrypto.a
LIBSRC= bio_lib.c bio_cb.c bio_err.c \
	bss_mem.c bss_null.c bss_fd.c \
	bss_file.c bss_sock.c bss_conn.c \
	bf_null.c bf_buff.c b_print.c b_dump.c \
	b_sock.c bss_acpt.c bf_nbio.c bss_log.c bss_bio.c \
	bss_dgram.c
#	bf_lbuf.c
LIBOBJ= bio_lib.o bio_cb.o bio_err.o \
	bss_mem.o bss_null.o bss_fd.o \
	bss_file.o bss_sock.o bss_conn.o \
	bf_null.o bf_buff.o b_print.o b_dump.o \
	b_sock.o bss_acpt.o bf_nbio.o bss_log.o bss_bio.o \
	bss_dgram.o
#	bf_lbuf.o

SRC= $(LIBSRC)

EXHEADER= bio.h
HEADER=	bio_lcl.h $(EXHEADER)

ALL=    $(GENERAL) $(SRC) $(HEADER)

top:
	(cd ../..; $(MAKE) DIRS=crypto SDIRS=$(DIR) sub_all)

all:	lib

lib:	$(LIBOBJ)
	$(AR) $(LIB) $(LIBOBJ)
	$(RANLIB) $(LIB) || echo Never mind.
	@touch lib

files:
	$(PERL) $(TOP)/util/files.pl Makefile >> $(TOP)/MINFO

links:
	@$(PERL) $(TOP)/util/mklink.pl ../../include/openssl $(EXHEADER)
	@$(PERL) $(TOP)/util/mklink.pl ../../test $(TEST)
	@$(PERL) $(TOP)/util/mklink.pl ../../apps $(APPS)

install:
	@[ -n "$(INSTALLTOP)" ] # should be set by top Makefile...
	@headerlist="$(EXHEADER)"; for i in $$headerlist; \
	do  \
	(cp $$i $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i; \
	chmod 644 $(INSTALL_PREFIX)$(INSTALLTOP)/include/openssl/$$i ); \
	done;

tags:
	ctags $(SRC)

tests:

lint:
	lint -DLINT $(INCLUDES) $(SRC)>fluff

update: depend

depend:
	@[ -n "$(MAKEDEPEND)" ] # should be set by upper Makefile...
	$(MAKEDEPEND) -- $(CFLAG) $(INCLUDES) $(DEPFLAG) -- $(PROGS) $(LIBSRC)

dclean:
	$(PERL) -pe 'if (/^# DO NOT DELETE THIS LINE/) {print; exit(0);}' $(MAKEFILE) >Makefile.new
	mv -f Makefile.new $(MAKEFILE)

clean:
	rm -f *.o *.obj lib tags core .pure .nfs* *.old *.bak fluff

# DO NOT DELETE THIS LINE -- make depend depends on it.

b_dump.o: ../../e_os.h ../../include/openssl/bio.h
b_dump.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
b_dump.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
b_dump.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
b_dump.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
b_dump.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
b_dump.o: ../../include/openssl/symhacks.h ../../ms/applink.c ../../ms/uplink.h
b_dump.o: ../cryptlib.h b_dump.c bio_lcl.h c:\mingw\include\_mingw.h
b_dump.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
b_dump.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
b_dump.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
b_dump.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
b_dump.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
b_dump.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
b_dump.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
b_dump.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
b_dump.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
b_dump.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
b_dump.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
b_dump.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
b_dump.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
b_dump.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
b_dump.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
b_dump.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
b_dump.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
b_dump.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
b_dump.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
b_print.o: ../../e_os.h ../../include/openssl/bio.h ../../include/openssl/bn.h
b_print.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
b_print.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
b_print.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
b_print.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
b_print.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
b_print.o: ../../include/openssl/symhacks.h ../../ms/applink.c
b_print.o: ../../ms/uplink.h ../cryptlib.h b_print.c c:\mingw\include\_mingw.h
b_print.o: c:\mingw\include\assert.h c:\mingw\include\basetsd.h
b_print.o: c:\mingw\include\ctype.h c:\mingw\include\dbt.h
b_print.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
b_print.o: c:\mingw\include\io.h c:\mingw\include\limits.h
b_print.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
b_print.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
b_print.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
b_print.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
b_print.o: c:\mingw\include\string.h c:\mingw\include\strings.h
b_print.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
b_print.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
b_print.o: c:\mingw\include\wctype.h c:\mingw\include\winbase.h
b_print.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
b_print.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
b_print.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
b_print.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
b_print.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
b_print.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
b_print.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
b_print.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
b_print.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
b_sock.o: ../../e_os.h ../../include/openssl/bio.h
b_sock.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
b_sock.o: ../../include/openssl/dso.h ../../include/openssl/e_os2.h
b_sock.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
b_sock.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
b_sock.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
b_sock.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
b_sock.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h b_sock.c
b_sock.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
b_sock.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
b_sock.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
b_sock.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
b_sock.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
b_sock.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
b_sock.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
b_sock.o: c:\mingw\include\string.h c:\mingw\include\strings.h
b_sock.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
b_sock.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
b_sock.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
b_sock.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
b_sock.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
b_sock.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
b_sock.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
b_sock.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
b_sock.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
b_sock.o: c:\mingw\include\ws2tcpip.h
b_sock.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
b_sock.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bf_buff.o: ../../e_os.h ../../include/openssl/bio.h
bf_buff.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bf_buff.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bf_buff.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bf_buff.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bf_buff.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bf_buff.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bf_buff.o: ../../ms/uplink.h ../cryptlib.h bf_buff.c c:\mingw\include\_mingw.h
bf_buff.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
bf_buff.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bf_buff.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
bf_buff.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bf_buff.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bf_buff.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bf_buff.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bf_buff.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bf_buff.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
bf_buff.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
bf_buff.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
bf_buff.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
bf_buff.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
bf_buff.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
bf_buff.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
bf_buff.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
bf_buff.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
bf_buff.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bf_buff.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bf_nbio.o: ../../e_os.h ../../include/openssl/bio.h
bf_nbio.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bf_nbio.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bf_nbio.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bf_nbio.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bf_nbio.o: ../../include/openssl/rand.h ../../include/openssl/safestack.h
bf_nbio.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
bf_nbio.o: ../../ms/applink.c ../../ms/uplink.h ../cryptlib.h bf_nbio.c
bf_nbio.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
bf_nbio.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
bf_nbio.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
bf_nbio.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
bf_nbio.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
bf_nbio.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
bf_nbio.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
bf_nbio.o: c:\mingw\include\string.h c:\mingw\include\strings.h
bf_nbio.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
bf_nbio.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bf_nbio.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
bf_nbio.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
bf_nbio.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
bf_nbio.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
bf_nbio.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
bf_nbio.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bf_nbio.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bf_nbio.o: c:\mingw\include\ws2tcpip.h
bf_nbio.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bf_nbio.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bf_null.o: ../../e_os.h ../../include/openssl/bio.h
bf_null.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bf_null.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bf_null.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bf_null.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bf_null.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bf_null.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bf_null.o: ../../ms/uplink.h ../cryptlib.h bf_null.c c:\mingw\include\_mingw.h
bf_null.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
bf_null.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bf_null.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
bf_null.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bf_null.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bf_null.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bf_null.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bf_null.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bf_null.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
bf_null.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
bf_null.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
bf_null.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
bf_null.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
bf_null.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
bf_null.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
bf_null.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
bf_null.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
bf_null.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bf_null.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bio_cb.o: ../../e_os.h ../../include/openssl/bio.h
bio_cb.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bio_cb.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bio_cb.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bio_cb.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bio_cb.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bio_cb.o: ../../include/openssl/symhacks.h ../../ms/applink.c ../../ms/uplink.h
bio_cb.o: ../cryptlib.h bio_cb.c c:\mingw\include\_mingw.h
bio_cb.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
bio_cb.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bio_cb.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
bio_cb.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bio_cb.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bio_cb.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bio_cb.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bio_cb.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bio_cb.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
bio_cb.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
bio_cb.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
bio_cb.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
bio_cb.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
bio_cb.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
bio_cb.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
bio_cb.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
bio_cb.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
bio_cb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bio_cb.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bio_err.o: ../../include/openssl/bio.h ../../include/openssl/crypto.h
bio_err.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bio_err.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bio_err.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bio_err.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bio_err.o: ../../include/openssl/symhacks.h bio_err.c c:\mingw\include\_mingw.h
bio_err.o: c:\mingw\include\errno.h c:\mingw\include\msvcrtver.h
bio_err.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdio.h
bio_err.o: c:\mingw\include\stdlib.h c:\mingw\include\sys/types.h
bio_err.o: c:\mingw\include\w32api.h
bio_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bio_err.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bio_lib.o: ../../e_os.h ../../include/openssl/bio.h
bio_lib.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bio_lib.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bio_lib.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bio_lib.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bio_lib.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bio_lib.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bio_lib.o: ../../ms/uplink.h ../cryptlib.h bio_lib.c c:\mingw\include\_mingw.h
bio_lib.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
bio_lib.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bio_lib.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
bio_lib.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bio_lib.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bio_lib.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bio_lib.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bio_lib.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bio_lib.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
bio_lib.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
bio_lib.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
bio_lib.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
bio_lib.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
bio_lib.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
bio_lib.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
bio_lib.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
bio_lib.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
bio_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bio_lib.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_acpt.o: ../../e_os.h ../../include/openssl/bio.h
bss_acpt.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bss_acpt.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bss_acpt.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bss_acpt.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bss_acpt.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bss_acpt.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bss_acpt.o: ../../ms/uplink.h ../cryptlib.h bss_acpt.c
bss_acpt.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
bss_acpt.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
bss_acpt.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
bss_acpt.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
bss_acpt.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
bss_acpt.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
bss_acpt.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
bss_acpt.o: c:\mingw\include\string.h c:\mingw\include\strings.h
bss_acpt.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
bss_acpt.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bss_acpt.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
bss_acpt.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
bss_acpt.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
bss_acpt.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
bss_acpt.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
bss_acpt.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bss_acpt.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bss_acpt.o: c:\mingw\include\ws2tcpip.h
bss_acpt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_acpt.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_bio.o: ../../e_os.h ../../include/openssl/bio.h
bss_bio.o: ../../include/openssl/crypto.h ../../include/openssl/e_os2.h
bss_bio.o: ../../include/openssl/err.h ../../include/openssl/lhash.h
bss_bio.o: ../../include/openssl/opensslconf.h ../../include/openssl/opensslv.h
bss_bio.o: ../../include/openssl/ossl_typ.h ../../include/openssl/safestack.h
bss_bio.o: ../../include/openssl/stack.h ../../include/openssl/symhacks.h
bss_bio.o: bss_bio.c c:\mingw\include\_mingw.h c:\mingw\include\assert.h
bss_bio.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
bss_bio.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bss_bio.o: c:\mingw\include\io.h c:\mingw\include\limits.h
bss_bio.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
bss_bio.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
bss_bio.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
bss_bio.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
bss_bio.o: c:\mingw\include\string.h c:\mingw\include\strings.h
bss_bio.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
bss_bio.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bss_bio.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
bss_bio.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
bss_bio.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
bss_bio.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
bss_bio.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
bss_bio.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bss_bio.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bss_bio.o: c:\mingw\include\ws2tcpip.h
bss_bio.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_bio.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_conn.o: ../../e_os.h ../../include/openssl/bio.h
bss_conn.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bss_conn.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bss_conn.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bss_conn.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bss_conn.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bss_conn.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bss_conn.o: ../../ms/uplink.h ../cryptlib.h bss_conn.c
bss_conn.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
bss_conn.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
bss_conn.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
bss_conn.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
bss_conn.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
bss_conn.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
bss_conn.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
bss_conn.o: c:\mingw\include\string.h c:\mingw\include\strings.h
bss_conn.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
bss_conn.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bss_conn.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
bss_conn.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
bss_conn.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
bss_conn.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
bss_conn.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
bss_conn.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bss_conn.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bss_conn.o: c:\mingw\include\ws2tcpip.h
bss_conn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_conn.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_dgram.o: ../../e_os.h ../../include/openssl/bio.h
bss_dgram.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bss_dgram.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bss_dgram.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bss_dgram.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bss_dgram.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bss_dgram.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bss_dgram.o: ../../ms/uplink.h ../cryptlib.h bss_dgram.c
bss_dgram.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
bss_dgram.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
bss_dgram.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
bss_dgram.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
bss_dgram.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
bss_dgram.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
bss_dgram.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
bss_dgram.o: c:\mingw\include\string.h c:\mingw\include\strings.h
bss_dgram.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
bss_dgram.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bss_dgram.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
bss_dgram.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
bss_dgram.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
bss_dgram.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
bss_dgram.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
bss_dgram.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bss_dgram.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bss_dgram.o: c:\mingw\include\ws2tcpip.h
bss_dgram.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_dgram.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_fd.o: ../../e_os.h ../../include/openssl/bio.h
bss_fd.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bss_fd.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bss_fd.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bss_fd.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bss_fd.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bss_fd.o: ../../include/openssl/symhacks.h ../../ms/applink.c ../../ms/uplink.h
bss_fd.o: ../cryptlib.h bio_lcl.h bss_fd.c c:\mingw\include\_mingw.h
bss_fd.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
bss_fd.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bss_fd.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
bss_fd.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bss_fd.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bss_fd.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bss_fd.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bss_fd.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bss_fd.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
bss_fd.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
bss_fd.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
bss_fd.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
bss_fd.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
bss_fd.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
bss_fd.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
bss_fd.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
bss_fd.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
bss_fd.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_fd.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_file.o: ../../e_os.h ../../include/openssl/bio.h
bss_file.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bss_file.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bss_file.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bss_file.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bss_file.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bss_file.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bss_file.o: ../../ms/uplink.h ../cryptlib.h bio_lcl.h bss_file.c
bss_file.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
bss_file.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
bss_file.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
bss_file.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
bss_file.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
bss_file.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
bss_file.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
bss_file.o: c:\mingw\include\string.h c:\mingw\include\strings.h
bss_file.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
bss_file.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bss_file.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
bss_file.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
bss_file.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
bss_file.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
bss_file.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
bss_file.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bss_file.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bss_file.o: c:\mingw\include\ws2tcpip.h
bss_file.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_file.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_log.o: ../../e_os.h ../../include/openssl/bio.h
bss_log.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bss_log.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bss_log.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bss_log.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bss_log.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bss_log.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bss_log.o: ../../ms/uplink.h ../cryptlib.h bss_log.c c:\mingw\include\_mingw.h
bss_log.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
bss_log.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bss_log.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
bss_log.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bss_log.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bss_log.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bss_log.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bss_log.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bss_log.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
bss_log.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
bss_log.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
bss_log.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
bss_log.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
bss_log.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
bss_log.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
bss_log.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
bss_log.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
bss_log.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_log.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_mem.o: ../../e_os.h ../../include/openssl/bio.h
bss_mem.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bss_mem.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bss_mem.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bss_mem.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bss_mem.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bss_mem.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bss_mem.o: ../../ms/uplink.h ../cryptlib.h bss_mem.c c:\mingw\include\_mingw.h
bss_mem.o: c:\mingw\include\basetsd.h c:\mingw\include\dbt.h
bss_mem.o: c:\mingw\include\errno.h c:\mingw\include\fcntl.h
bss_mem.o: c:\mingw\include\io.h c:\mingw\include\malloc.h
bss_mem.o: c:\mingw\include\msvcrtver.h c:\mingw\include\poppack.h
bss_mem.o: c:\mingw\include\pshpack4.h c:\mingw\include\sdkddkver.h
bss_mem.o: c:\mingw\include\stdint.h c:\mingw\include\stdio.h
bss_mem.o: c:\mingw\include\stdlib.h c:\mingw\include\string.h
bss_mem.o: c:\mingw\include\strings.h c:\mingw\include\sys/types.h
bss_mem.o: c:\mingw\include\sys\types.h c:\mingw\include\w32api.h
bss_mem.o: c:\mingw\include\wchar.h c:\mingw\include\winbase.h
bss_mem.o: c:\mingw\include\wincon.h c:\mingw\include\windef.h
bss_mem.o: c:\mingw\include\windows.h c:\mingw\include\winerror.h
bss_mem.o: c:\mingw\include\wingdi.h c:\mingw\include\winnetwk.h
bss_mem.o: c:\mingw\include\winnls.h c:\mingw\include\winnt.h
bss_mem.o: c:\mingw\include\winreg.h c:\mingw\include\winsock2.h
bss_mem.o: c:\mingw\include\winsvc.h c:\mingw\include\winuser.h
bss_mem.o: c:\mingw\include\winver.h c:\mingw\include\ws2tcpip.h
bss_mem.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_mem.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_null.o: ../../e_os.h ../../include/openssl/bio.h
bss_null.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bss_null.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bss_null.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bss_null.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bss_null.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bss_null.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bss_null.o: ../../ms/uplink.h ../cryptlib.h bss_null.c
bss_null.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
bss_null.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
bss_null.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
bss_null.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
bss_null.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
bss_null.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
bss_null.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
bss_null.o: c:\mingw\include\string.h c:\mingw\include\strings.h
bss_null.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
bss_null.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bss_null.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
bss_null.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
bss_null.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
bss_null.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
bss_null.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
bss_null.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bss_null.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bss_null.o: c:\mingw\include\ws2tcpip.h
bss_null.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_null.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
bss_sock.o: ../../e_os.h ../../include/openssl/bio.h
bss_sock.o: ../../include/openssl/buffer.h ../../include/openssl/crypto.h
bss_sock.o: ../../include/openssl/e_os2.h ../../include/openssl/err.h
bss_sock.o: ../../include/openssl/lhash.h ../../include/openssl/opensslconf.h
bss_sock.o: ../../include/openssl/opensslv.h ../../include/openssl/ossl_typ.h
bss_sock.o: ../../include/openssl/safestack.h ../../include/openssl/stack.h
bss_sock.o: ../../include/openssl/symhacks.h ../../ms/applink.c
bss_sock.o: ../../ms/uplink.h ../cryptlib.h bss_sock.c
bss_sock.o: c:\mingw\include\_mingw.h c:\mingw\include\basetsd.h
bss_sock.o: c:\mingw\include\dbt.h c:\mingw\include\errno.h
bss_sock.o: c:\mingw\include\fcntl.h c:\mingw\include\io.h
bss_sock.o: c:\mingw\include\malloc.h c:\mingw\include\msvcrtver.h
bss_sock.o: c:\mingw\include\poppack.h c:\mingw\include\pshpack4.h
bss_sock.o: c:\mingw\include\sdkddkver.h c:\mingw\include\stdint.h
bss_sock.o: c:\mingw\include\stdio.h c:\mingw\include\stdlib.h
bss_sock.o: c:\mingw\include\string.h c:\mingw\include\strings.h
bss_sock.o: c:\mingw\include\sys/types.h c:\mingw\include\sys\types.h
bss_sock.o: c:\mingw\include\w32api.h c:\mingw\include\wchar.h
bss_sock.o: c:\mingw\include\winbase.h c:\mingw\include\wincon.h
bss_sock.o: c:\mingw\include\windef.h c:\mingw\include\windows.h
bss_sock.o: c:\mingw\include\winerror.h c:\mingw\include\wingdi.h
bss_sock.o: c:\mingw\include\winnetwk.h c:\mingw\include\winnls.h
bss_sock.o: c:\mingw\include\winnt.h c:\mingw\include\winreg.h
bss_sock.o: c:\mingw\include\winsock2.h c:\mingw\include\winsvc.h
bss_sock.o: c:\mingw\include\winuser.h c:\mingw\include\winver.h
bss_sock.o: c:\mingw\include\ws2tcpip.h
bss_sock.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stdarg.h
bss_sock.o: c:\mingw\lib\gcc\mingw32\6.3.0\include\stddef.h
