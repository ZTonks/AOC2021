$define INPUT "/home/zak/AOC2021/day4/input"
$define NUMLISTLOCAL 'nonemptylist'( 'nonnegint' )
$define NUMLISTPARAM nonemptylist( nonnegint )
$define BINGOSIZE 5

####################################

solvePuzzle := proc($) :: posint;

local fd :: 'nonnegint' := fopen(INPUT, ':-READ'),
      line :: 'Or'( 'string', 'identical'( 0 ) ),
      bingoNumbers :: NUMLISTLOCAL,
      bingoCards :: 'Array'( 'Array'( NUMLISTLOCAL ) ) := Array([]),
      bingoCardsNext :: 'Array'( 'Array'( NUMLISTLOCAL ) ) := Array([]),
      bingoCard :: 'Or'( 'identical'( NULL ), 'Array'( NUMLISTLOCAL ) ),
      called :: 'Array'( 'nonnegint' ) := Array([]),
      x :: 'nonnegint',
      bingoCardResult :: 'nonnegint';

line := readline(fd);

if line = 0 then
    error "failed to read first line of bingo numbers";
end if;

bingoNumbers := map(parse, StringTools:-Split(line, ","));

readBingoCards(fd, bingoCardsNext);

for x in bingoNumbers do

    bingoCards := bingoCardsNext;

    bingoCardsNext := Array([]);

    called ,= x;

    for bingoCard in bingoCards do

        bingoCardResult := evaluateBingoCard(bingoCard, called);

        if not type(bingoCardResult, 'posint') then

            bingoCardsNext ,= bingoCard;

        elif numelems(bingoCards) = 1 then

            return bingoCardResult;

        end if;

    end do;

end do;

return bingoCardResult;

end proc:

####################################

readBingoCards := proc(
    fd :: nonnegint,
    bingoCards :: Array( Array( NUMLISTPARAM ) ),
    $
)

local bingoCardNo :: 'nonnegint' := 0,
      bingoCardLine :: 'integer'[ 0 .. 5 ],
      line :: 'Or'( 'string', 'identical'( 0 ) );

while (line := readline(fd)) <> 0 do

    if length(line) = 0 then

        local j :: 'posint';

        bingoCardNo++;

        bingoCardLine := 0;

        bingoCards ,= Array( 1 .. BINGOSIZE,
            () -> [ seq( 0, j in 1 .. BINGOSIZE ) ]);

    else

        bingoCards[bingoCardNo][++bingoCardLine] :=
            map( parse, StringTools:-Split(line) );

    end if;

end do;

end proc:

####################################

evaluateBingoCard := proc(
    bingoCard :: Array( NUMLISTPARAM ),
    bingoNumbers :: Array( nonnegint ),
    $
) :: nonnegint;

local i :: 'posint',
      row :: NUMLISTLOCAL,
      col :: 'Array'( 'nonnegint' ),
      diag :: NUMLISTLOCAL,
      evalCollectionCallback :=
        collection ->
            andmap( y -> ormap( x -> x = y, bingoNumbers ), collection );

for row in bingoCard do

    if evalCollectionCallback(row) then

        return addUnmarkedNumbers(bingoCard, bingoNumbers) * bingoNumbers[ -1 ];

    end if;

end do;

for i to BINGOSIZE do

    col := map( row -> row[ i ], bingoCard );

    if evalCollectionCallback(col) then

        return addUnmarkedNumbers(bingoCard, bingoNumbers) * bingoNumbers[ -1 ];

    end if;

end do;

# diag := [ seq( bingoCard[ i ][ i ], i in 1 .. BINGOSIZE ) ];

# if evalCollectionCallback(diag) then

#     return addUnmarkedNumbers(bingoCard, bingoNumbers) * bingoNumbers[ -1 ];

# end if;

# diag := [ seq( bingoCard[ BINGOSIZE - i + 1 ][ i ], i in 1 .. BINGOSIZE ) ];

# if evalCollectionCallback(diag) then

#     return addUnmarkedNumbers(bingoCard, bingoNumbers) * bingoNumbers[ -1 ];

# end if;

return 0;

end proc:

####################################

getLastCalledNumber := proc(
    row :: NUMLISTPARAM,
    bingoNumbers :: NUMLISTPARAM,
    $
) :: nonnegint;

local lastCalled :: 'nonnegint',
      x :: 'nonnegint';

for x in bingoNumbers do

    if ormap( y -> y = x, row ) then

        lastCalled := x;

    end if;

end do;

if not type( lastCalled, 'nonnegint' ) then
    error "BAD";
end if;

return lastCalled;

end proc:

####################################

addUnmarkedNumbers := proc(
    bingoCard :: Array( NUMLISTPARAM ),
    bingoNumbers :: Array( nonnegint ),
    $
) :: nonnegint;

local sumOut :: 'nonnegint' := 0,
      row :: NUMLISTLOCAL,
      x :: 'nonnegint';

for row in bingoCard do

    for x in row do

        if not ormap( y -> y = x, bingoNumbers ) then

            sumOut += x;

        end if;

    end do;

end do;

return sumOut;

end proc:

####################################

solvePuzzle();

$undef INPUT
$undef NUMLISTLOCAL
$undef NUMLISTPARAM
$undef BINGOSIZE
