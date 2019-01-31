-module(game).
-export([start/0, ping/2, pong/0]).

ping(0, Pong_PID)->
             Pong_PID ! finished,
             io:format("Ping finished~n",[]);

ping(X, Pong_PID)->
             Pong_PID ! {ping, self()},
             receive
                           pong->
                                        io:format("Ping received pong~n",[])
             end,
             ping(X, Pong_PID).
pong()->
            receive
                          finished->
                                        io:format("Pong finished~n", []);
                          {ping, Ping_PID}->
                                        io:format("Pong received ping~n", []),
                                        Ping_PID ! pong, pong()
                          end.
start()->
            Pong_PID = spawn(game, pong, []),
            spawn(game, ping, [3, Pong_PID]).
