TOPDIR=../..
include $(TOPDIR)/make.inc

########################################################################
#  This is the makefile for the eigenvalue test program from LAPACK.
#  The test files are organized as follows:
#
#     AEIGTST -- Auxiliary test routines used in all precisions
#     SCIGTST -- Auxiliary test routines used in REAL and COMPLEX
#     DZIGTST -- Auxiliary test routines used in DOUBLE PRECISION and
#                COMPLEX*16
#     SEIGTST -- Single precision real test routines
#     CEIGTST -- Single precision complex test routines
#     DEIGTST -- Double precision real test routines
#     ZEIGTST -- Double precision complex test routines
#
#  Test programs can be generated for all or some of the four different
#  precisions.  Enter make followed by one or more of the data types
#  desired.  Some examples:
#       make single
#       make single complex
#       make single double complex complex16
#  Alternatively, the command
#       make
#  without any arguments creates all four test programs.
#  The executable files are called
#       xeigtsts, xeigtstd, xeigtstc, and xeigtstz
#  and are created in the next higher directory level.
#
#  To remove the object files after the executable files have been
#  created, enter
#       make clean
#  On some systems, you can force the source files to be recompiled by
#  entering (for example)
#       make single FRC=FRC
#
########################################################################

AEIGTST = \
   alahdg.o \
   alasum.o \
   alasvm.o \
   alareq.o \
   ilaenv.o \
   xerbla.o \
   xlaenv.o \
   chkxer.o

SCIGTST = slafts.o slahd2.o slasum.o slatb9.o sstech.o sstect.o \
   ssvdch.o ssvdct.o ssxt1.o

SEIGTST = schkee.o \
   sbdt01.o sbdt02.o sbdt03.o \
   schkbb.o schkbd.o schkbk.o schkbl.o schkec.o \
   schkgg.o schkgk.o schkgl.o schkhs.o schksb.o schkst.o \
   sckglm.o sckgqr.o sckgsv.o scklse.o \
   sdrges.o sdrgev.o sdrgsx.o sdrgvx.o \
   sdrvbd.o sdrves.o sdrvev.o sdrvgg.o sdrvsg.o \
   sdrvst.o sdrvsx.o sdrvvx.o \
   serrbd.o serrec.o serred.o serrgg.o serrhs.o serrst.o \
   sget02.o sget10.o sget22.o sget23.o sget24.o sget31.o \
   sget32.o sget33.o sget34.o sget35.o sget36.o \
   sget37.o sget38.o sget39.o sget51.o sget52.o sget53.o \
   sget54.o sglmts.o sgqrts.o sgrqts.o sgsvts.o \
   shst01.o slarfy.o slarhs.o slatm4.o slctes.o slctsx.o slsets.o sort01.o \
   sort03.o ssbt21.o ssgt01.o sslect.o sspt21.o sstt21.o \
   sstt22.o ssyt21.o ssyt22.o

CEIGTST = cchkee.o \
   cbdt01.o cbdt02.o cbdt03.o \
   cchkbb.o cchkbd.o cchkbk.o cchkbl.o cchkec.o \
   cchkgg.o cchkgk.o cchkgl.o cchkhb.o cchkhs.o cchkst.o \
   cckglm.o cckgqr.o cckgsv.o ccklse.o \
   cdrges.o cdrgev.o cdrgsx.o cdrgvx.o \
   cdrvbd.o cdrves.o cdrvev.o cdrvgg.o cdrvsg.o \
   cdrvst.o cdrvsx.o cdrvvx.o \
   cerrbd.o cerrec.o cerred.o cerrgg.o cerrhs.o cerrst.o \
   cget02.o cget10.o cget22.o cget23.o cget24.o \
   cget35.o cget36.o cget37.o cget38.o cget51.o cget52.o \
   cget54.o cglmts.o cgqrts.o cgrqts.o cgsvts.o \
   chbt21.o chet21.o chet22.o chpt21.o chst01.o \
   clarfy.o clarhs.o clatm4.o clctes.o clctsx.o clsets.o csbmv.o \
   csgt01.o cslect.o \
   cstt21.o cstt22.o cunt01.o cunt03.o

DZIGTST = dlafts.o dlahd2.o dlasum.o dlatb9.o dstech.o dstect.o \
   dsvdch.o dsvdct.o dsxt1.o

DEIGTST = dchkee.o \
   dbdt01.o dbdt02.o dbdt03.o \
   dchkbb.o dchkbd.o dchkbk.o dchkbl.o dchkec.o \
   dchkgg.o dchkgk.o dchkgl.o dchkhs.o dchksb.o dchkst.o \
   dckglm.o dckgqr.o dckgsv.o dcklse.o \
   ddrges.o ddrgev.o ddrgsx.o ddrgvx.o \
   ddrvbd.o ddrves.o ddrvev.o ddrvgg.o ddrvsg.o \
   ddrvst.o ddrvsx.o ddrvvx.o \
   derrbd.o derrec.o derred.o derrgg.o derrhs.o derrst.o \
   dget02.o dget10.o dget22.o dget23.o dget24.o dget31.o \
   dget32.o dget33.o dget34.o dget35.o dget36.o \
   dget37.o dget38.o dget39.o dget51.o dget52.o dget53.o \
   dget54.o dglmts.o dgqrts.o dgrqts.o dgsvts.o \
   dhst01.o dlarfy.o dlarhs.o dlatm4.o dlctes.o dlctsx.o dlsets.o dort01.o \
   dort03.o dsbt21.o dsgt01.o dslect.o dspt21.o dstt21.o \
   dstt22.o dsyt21.o dsyt22.o

ZEIGTST = zchkee.o \
   zbdt01.o zbdt02.o zbdt03.o \
   zchkbb.o zchkbd.o zchkbk.o zchkbl.o zchkec.o \
   zchkgg.o zchkgk.o zchkgl.o zchkhb.o zchkhs.o zchkst.o \
   zckglm.o zckgqr.o zckgsv.o zcklse.o \
   zdrges.o zdrgev.o zdrgsx.o zdrgvx.o \
   zdrvbd.o zdrves.o zdrvev.o zdrvgg.o zdrvsg.o \
   zdrvst.o zdrvsx.o zdrvvx.o \
   zerrbd.o zerrec.o zerred.o zerrgg.o zerrhs.o zerrst.o \
   zget02.o zget10.o zget22.o zget23.o zget24.o \
   zget35.o zget36.o zget37.o zget38.o zget51.o zget52.o \
   zget54.o zglmts.o zgqrts.o zgrqts.o zgsvts.o \
   zhbt21.o zhet21.o zhet22.o zhpt21.o zhst01.o \
   zlarfy.o zlarhs.o zlatm4.o zlctes.o zlctsx.o zlsets.o zsbmv.o \
   zsgt01.o zslect.o \
   zstt21.o zstt22.o zunt01.o zunt03.o

all: single complex double complex16

single: ../xeigtsts$(PLAT)
complex: ../xeigtstc$(PLAT)
double: ../xeigtstd$(PLAT)
complex16: ../xeigtstz$(PLAT)

../xeigtsts$(PLAT): $(SEIGTST) $(SCIGTST) $(AEIGTST) ; \
          $(CC) $(LOADOPTS)   -o xeigtsts$(PLAT) \
          $(SEIGTST) $(SCIGTST) $(AEIGTST) ../../$(TMGLIB) \
		  ../../INSTALL/second.o \
	  ../../$(LAPACKLIB) $(BLASLIB) $(F2CLIB) -lm && mv xeigtsts$(PLAT) $@

../xeigtstc$(PLAT): $(CEIGTST) $(SCIGTST) $(AEIGTST) ; \
          $(CC) $(LOADOPTS)   -o xeigtstc$(PLAT) \
          $(CEIGTST) $(SCIGTST) $(AEIGTST) ../../$(TMGLIB) \
		  ../../INSTALL/second.o \
	  ../../$(LAPACKLIB) $(BLASLIB) $(F2CLIB) -lm && mv xeigtstc$(PLAT) $@

../xeigtstd$(PLAT): $(DEIGTST) $(DZIGTST) $(AEIGTST) ; \
          $(CC) $(LOADOPTS)   -o xeigtstd$(PLAT) \
          $(DEIGTST) $(DZIGTST) $(AEIGTST) ../../$(TMGLIB) \
		  ../../INSTALL/dsecnd.o \
	  ../../$(LAPACKLIB) $(BLASLIB) $(F2CLIB) -lm && mv xeigtstd$(PLAT) $@

../xeigtstz$(PLAT): $(ZEIGTST) $(DZIGTST) $(AEIGTST) ; \
          $(CC) $(LOADOPTS)   -o xeigtstz$(PLAT) \
          $(ZEIGTST) $(DZIGTST) $(AEIGTST) ../../$(TMGLIB) \
		  ../../INSTALL/dsecnd.o \
	  ../../$(LAPACKLIB) $(BLASLIB) $(F2CLIB) -lm && mv xeigtstz$(PLAT) $@

$(AEIGTST): $(FRC)
$(SCIGTST): $(FRC)
$(DZIGTST): $(FRC)
$(SEIGTST): $(FRC)
$(CEIGTST): $(FRC)
$(DEIGTST): $(FRC)
$(ZEIGTST): $(FRC)

FRC:
	@FRC=$(FRC)

clean:
	rm -f *.o

schkee.o: schkee.c
	$(CC) $(DRVCFLAGS) -c $< -o $@
dchkee.o: dchkee.c
	$(CC) $(DRVCFLAGS) -c $< -o $@
cchkee.o: cchkee.c
	$(CC) $(DRVCFLAGS) -c $< -o $@
zchkee.o: zchkee.c
	$(CC) $(DRVCFLAGS) -c $< -o $@

.c.o : ; $(CC) $(CFLAGS) -c $<
