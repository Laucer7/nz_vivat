
:- use_module('pl-man-game/main.pl').

:- dynamic todo/1.

todo(go(up)).

s(DIR, OBJ):- see(normal, DIR, OBJ).
chng_stat(S2) :-retract(todo(_)), assert(todo(S2)), term_string(S2, STRING), writeln(STRING).

do(move(none)) :- todo(go(up)), s(up, '#'), s(right, '.'), chng_stat(go(right-downc)).
do(move(none)) :- todo(go(up)), s(up, '#'), not(s(right, '.')), chng_stat(go(right)).
do(move(right)) :- todo(go(right-downc)), chng_stat(go(down)).
do(move(none)) :- todo(go(down)), s(down, '#'), s(right, '.'), chng_stat(go(right-upc)).
do(move(right)) :- todo(go(right-upc)), chng_stat(go(up)).

do(move(none)) :- todo(go(right)), s(right, '#'), chng_stat(go(down2)).
do(move(none)) :- todo(go(down2)), s(down, '#'), chng_stat(go(left-upc)).
do(move(right)) :- todo(go(left-upc)), chng_stat(go(up)).


do(move(right)) :- todo(go(right-downc)).
do(move(right)) :- todo(go(right-upc)).
do(move(right)) :- todo(go(left-upc)).
do(move(up)) :- todo(go(up)).
do(move(down)) :- todo(go(down)).
do(move(down)) :- todo(go(down2)).
do(move(left)) :- todo(go(left)), not(s(right, 'E')).
do(move(none)) :- todo(go(right)), s(right, 'E').
do(move(none)) :- todo(go(right)),  s(right-down, 'E'), not(s(down, '#')).
do(move(right)) :- todo(go(right)).


