#
# The one_test command runs one test, while the do_experiment command
# runs all the experiments in an orderly way, presenting the results
# in an orderly way.
#
KUID = CHANGE_ME_TO_YOUR_KUID
LAB_NAME = complexity

OBJECT_FILES = utility.o bubbleSort.o insertionSort.o mergesort.o quicksort.o selectionSort.o

all: one_test

one_test: one_test.o $(OBJECT_FILES)
	g++ -o one_test one_test.o $(OBJECT_FILES)

one_test.o: one_test.cpp 
	g++ -c one_test.cpp 

do_experiment: do_experiment.o $(OBJECT_FILES)
	g++ -o do_experiment do_experiment.o $(OBJECT_FILES)

do_experiment.o: do_experiment.cpp 
	g++ -c do_experiment.cpp 

utility.o: utility.cpp 
	g++ -c utility.cpp 

bubbleSort.o: bubbleSort.cpp 
	g++ -c bubbleSort.cpp 

insertionSort.o: insertionSort.cpp 
	g++ -c insertionSort.cpp 

mergesort.o: mergesort.cpp 
	g++ -c mergesort.cpp 

quicksort.o: quicksort.cpp 
	g++ -c quicksort.cpp 

selectionSort.o: selectionSort.cpp
	g++ -c selectionSort.cpp

test1: one_test
	./one_test 100 random bubble
	./one_test 100 random insertion
	./one_test 100 random merge
	./one_test 100 random quick random
	./one_test 100 random quick mo3
	./one_test 100 random quick default
	./one_test 100 random selection

test2: do_experiment
	./do_experiment

test3: one_test
	./one_test 1000 descending bubble

# Put starter code targets here

tar-file: clean
	@if test -d ../$(KUID)_$(LAB_NAME) ; then \
		( cd .. ; \
		  tar cz $(KUID)_$(LAB_NAME) >$(KUID)_$(LAB_NAME).tar.gz ; \
	  	  echo ""; \
		  echo "**************************************************************"; \
		  echo "The TAR file for you to test and hand in "; \
		  echo "   has been made in the directory above:"; \
		  echo "     " $(KUID)_$(LAB_NAME).tar.gz ; \
		  echo "**************************************************************"; \
		) ; \
	else \
		( echo "*** ERROR ** ERROR ** ERROR ** ERROR ** ERROR ** ERROR ***"; \
		  echo "The <your KUID>_<lab-name> directory was not found. "; \
		  echo "Remember that you should rename the "; \
		  echo "\"starter-code\" directory created by the "; \
		  echo "starter TAR file and set the KUID " ; \
		  echo "variable in the Makefile"; \
		) ; \
	fi


# Remember to add executables to the clean target
#
clean:
	rm -f *.o *~ one_test do_experiment
