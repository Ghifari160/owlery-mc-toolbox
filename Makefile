BUILD := ./BUILD
OBJ_DIR := $(BUILD)/Objects
APP_DIR := $(BUILD)/Products

RELEASE :=
DEBUG   :=

RELEASE += Faction\ Generator_release
Faction\ Generator_release:
	$(MAKE) -C Faction\ Generator -f Makefile.release all

DEBUG += Faction\ Generator_debug
Faction\ Generator_debug:
	$(MAKE) -C Faction\ Generator -f Makefile.debug all

.PHONY: $(RELEASE) $(DEBUG) release debug clean

release: $(RELEASE)

debug: $(DEBUG)

clean:
	-@rm -rvf $(OBJ_DIR)
	-@rm -rvf $(APP_DIR)