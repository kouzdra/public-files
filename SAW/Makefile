P ?= funcs

saw: $(P).bc
	saw $(P).saw

$(P).bc: $(P).c
	clang -g -emit-llvm -c $< -o $@

clean:
	rm -f *.bc *.class *.smt *.aig *.out *~
