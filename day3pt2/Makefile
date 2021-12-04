COMPILER=gcc

main:
	@$(COMPILER) -D NUMCOLS=12 \
		-D OXYGEN_GENERATOR_RATING 1 \
		-D CO2_SCRUBBER_RATING 0 \
		-D MAX_LINES 1000 \
		src/binaryfuncs.c src/main.c \
		-I include/ \
		-o bin/main

	@echo "build succeeded"
