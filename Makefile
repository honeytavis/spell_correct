DIRS = spell_correct 

PHONY += all
all:
	cd $(DIRS); make

PHONY += clean 
clean:
	cd $(DIRS); make clean

.PHONY : PHONY
