all: everything
clean: cleaneverything
#realclean: realcleaneverything

codeUnity:
	make -i -f MakefileUnity.mk
	
cleanCodeUnity:
	make -i -f MakefileUnity.mk clean
	
everything: 
	make -i -f MakefileUnity.mk

cleaneverything:
	make -i -f MakefileUnity.mk clean

#realcleaneverything:
#	make -i -f MakefileUnity.mk realclean
