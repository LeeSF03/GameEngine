#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern ge::Application* ge::CreateApplication();

int main(int argc, char const *argv[])
{
  ge::Log::Init();
  GE_CORE_WARN("Initialized Core Log");

  int a = 1;
  GE_INFO("Hello Var={0}", a);

  auto app = ge::CreateApplication();
  app->Run();
  return 0;
}
#endif