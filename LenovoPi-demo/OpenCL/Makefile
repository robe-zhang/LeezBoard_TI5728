.SILENT:

MFS  = $(wildcard */Makefile)
DIRS = $(patsubst %/Makefile,%,$(MFS))

all:
	for dir in $(DIRS); do \
	  echo "building [$$dir]" ; \
	  $(MAKE) -C $$dir; \
	done

clean:
	for dir in $(DIRS); do \
	  echo "cleaning [$$dir]" ; \
	  $(MAKE) -C $$dir clean; \
	done
