#pragma once

#ifdef GE_PLATFORM_WINDOWS

extern ge::Application* ge::CreateApplication();

int main(int argc, char const *argv[])
{
  auto app = ge::CreateApplication();
  app->Run();
  return 0;
}
#endif