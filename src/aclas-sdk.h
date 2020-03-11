#ifndef ACLAS_SDK_H
#define ACLAS_SDK_H

#include <napi.h>

class AclasSdk: public Napi::ObjectWrap<AclasSdk> {
  public:
    static Napi::Object Init(Napi::Env env, Napi::Object exports);
    AclasSdk(const Napi::CallbackInfo& info);

  private:
    static Napi::FunctionReference constructor;

    Napi::Value Aclas_Initialize(const Napi::CallbackInfo& info);
    Napi::Value Aclas_Finalize(const Napi::CallbackInfo& info);
    Napi::Value Aclas_GetInfo(const Napi::CallbackInfo& info);
    Napi::Value Aclas_ExecTaskWithCB(const Napi::CallbackInfo& info);
};

#endif
