
:- use_module('pl-man-game/main.pl').
do(move(left)) :- see(normal, left, 'D').
do(move(left)) :- see(normal, left, '.').

