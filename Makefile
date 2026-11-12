TOP ?= tb_regfile

.PHONY: lint sim clean

lint:
	verilator --lint-only -Wall -Wno-fatal -Wno-EOFNEWLINE -Wno-UNUSEDPARAM -Wno-TIMESCALEMOD -Wno-MULTITOP -Wno-UNUSEDSIGNAL rtl/*.sv

sim:
	./scripts/sim.sh $(TOP)

clean:
	rm -rf build