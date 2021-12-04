$define OXYGEN_GENERATOR_RATING true
$define CO2_SCRUBBER_RATING false

$define NUMCOLS 12
$define MAXLINES 1000

#######################################

solvePuzzle := proc() :: posint;

local fileName :: 'string' := "/home/zak/AOC2021/day3/input",
      fd :: 'nonnegint',
      bitStringsOrig :: 'Array'( 'Array'( 'truefalse' ) ),
      bitArray :: 'Array'( 'truefalse' ),
      i :: 'posint',
      bit :: 'truefalse',
      line :: 'Or'( 'string', 'identical'( 0 ) ),
      x :: 'string',
      rating :: 'truefalse',
      outInner :: 'nonnegint',
      out :: 'posint',
      y :: 'truefalse';

    for rating in [ OXYGEN_GENERATOR_RATING, CO2_SCRUBBER_RATING ] do

        i := 1;

        bitStringsOrig := Array( 1 .. MAXLINES,
            () -> Array( 1 .. NUMCOLS, () -> false ) );

        fd := fopen(fileName, ':-READ');

        # read file into array of bit arrays
        while ((line := readline(fd)) <> 0) do

            bitArray := bitStringsOrig[i++];

            local j :: 'posint' := 1;

            for x in line do

                bitArray[j++] := evalb(parse(x) = 1);

            end do;

        end do;

        for i to NUMCOLS do

            bit := getMostCommonBitForCol(bitStringsOrig, i);

            if not rating then

                bit := not bit;

            end if;

            bitStringsOrig := writeArrayWithCommonBitInCol(
                bitStringsOrig, i, bit);

        until numelems(bitStringsOrig) = 1;

        outInner := 0;

        for i, y in bitStringsOrig[1] do

            outInner += `if`( y, 2^(NUMCOLS - i), 0 );

        end do;

        out := `if`( type( out, 'posint' ), out, 1) * outInner;

        fclose(fd);

    end do;

    return out;

end proc:

#######################################

getMostCommonBitForCol := proc(
    bitStrings :: Array,
    i :: posint
) :: truefalse;

local bitMap :: 'Array'( 'identical'( 0, 1 ) )
        := map( y -> `if`( y[i], 1, 0 ), bitStrings ),
      sumBits :: 'nonnegint' :=
        add( bitMap );

return evalb(2 * sumBits >= numelems( bitStrings ));

end proc:

#######################################

writeArrayWithCommonBitInCol := proc(
    bitStringsOrig :: Array,
    col :: posint,
    bit :: truefalse
) :: Array;

local x :: 'Array'( 'truefalse' ),
      bitStringsNext :: 'Array'( 'truefalse' ) := Array([]);

for x in bitStringsOrig do

    if x[col] = bit then

        bitStringsNext ,= x;

    end if;

end do;

return bitStringsNext;

end proc:

#######################################

$undef OXYGEN_GENERATOR_RATING
$undef CO2_SCRUBBER_RATING

solvePuzzle();
