PROJECT_ROOT = D:/GameEngine
include $(PROJECT_ROOT)/.env

PREPROCESSOR = -DGE_PLATFORM_WINDOWS -DGE_BUILD_DLL

_GAME_ENGINE_OBJS = Application.o Log.o
GAME_ENGINE_OBJS = $(patsubst %,$(GAME_ENGINE_ODIR)/%,$(_GAME_ENGINE_OBJS))

$(GAME_ENGINE_ODIR)/%.o: $(GAME_ENGINE_SDIR)/GE/%.cpp
	$(CC) -c $(GAME_ENGINE_INC) $(PREPROCESSOR) -o $@ $<

$(GAME_ENGINE_DLL_OUT): $(GAME_ENGINE_OBJS)
	$(CC) -H -shared $^ -o $(GAME_ENGINE_DLL_OUT) -Wl,--out-implib,$(GAME_ENGINE_STATIC_OUT) \
	&& cp $(GAME_ENGINE_DLL_OUT) $(SANDBOX_ODIR)/$(GAME_ENGINE_DLL_NAME).dll

.PHONY: clean

clean:
	rm -f $(GAME_ENGINE_ODIR)/*.o $(GAME_ENGINE_DLL_OUT) $(GAME_ENGINE_STATIC_OUT)