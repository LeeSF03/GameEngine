PROJECT_ROOT = D:/GameEngine
include $(PROJECT_ROOT)/.env

.PHONY: all clean pch

all:
	cd $(GAME_ENGINE_DIR) && make
	cd $(SANDBOX_DIR) && make

clean:
	cd $(GAME_ENGINE_DIR) && make $@
	cd $(SANDBOX_DIR) && make $@

pch: clean
	$(CC) $(FLAGS) $(GAME_ENGINE_SDIR)/gepch.h



# NOTE TO SELF
# the makefiles are seperated because both uses the same rules
# with the first rule cancelling the second rule