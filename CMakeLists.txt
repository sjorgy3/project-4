cmake_minimum_required(VERSION 3.17)
project(project_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(project_2
        Automaton.h
        ColonAutomaton.cpp
        ColonAutomaton.h
        ColonDashAutomaton.cpp
        ColonDashAutomaton.h
        CommaAutomaton.h
        CommaAutomaton.cpp
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h PeriodAutomaton.cpp PeriodAutomaton.h Q_MarkAutomaton.cpp Q_MarkAutomaton.h Left_ParenAutomaton.cpp Left_ParenAutomaton.h Right_ParenAutomaton.cpp Right_ParenAutomaton.h MultiplyAutomaton.cpp MultiplyAutomaton.h AddAutomaton.cpp AddAutomaton.h SchemesAutomaton.cpp SchemesAutomaton.h FactsAutomaton.cpp FactsAutomaton.h RulesAutomaton.cpp RulesAutomaton.h QueriesAutomaton.cpp QueriesAutomaton.h IDAutomaton.cpp IDAutomaton.h StringAutomaton.cpp StringAutomaton.h CommentAutomaton.cpp CommentAutomaton.h UndefinedAutomaton.cpp UndefinedAutomaton.h EOFAutomaton.cpp EOFAutomaton.h WhiteSpaceAutomaton.cpp WhiteSpaceAutomaton.h LineCommentAutomaton.cpp LineCommentAutomaton.h Parser.cpp Parser.h DatalogProgram.cpp DatalogProgram.h Predicate.cpp Predicate.h Rule.cpp Rule.h Parameter.cpp Parameter.h Database.cpp Database.h Relation.cpp Relation.h Interpreter.cpp Interpreter.h Tuple.cpp Tuple.h Header.cpp Header.h)
