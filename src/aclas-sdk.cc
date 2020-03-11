#include "aclas-sdk.h"

Napi::FunctionReference AclasSdk::constructor;

Napi::Object AclasSdk::Init(Napi::Env env, Napi::Object exports) {
  Napi::HandleScope scope(env);

  Napi::Function func = DefineClass(env, "AclasSdk", {
	  InstanceMethod("initialize", &AclasSdk::Aclas_Initialize),
	  InstanceMethod("finalize", &AclasSdk::Aclas_Finalize),
	  InstanceMethod("getInfo", &AclasSdk::Aclas_GetInfo),
	  InstanceMethod("execTaskWithCB", &AclasSdk::Aclas_ExecTaskWithCB)});

  constructor = Napi::Persistent(func);
  constructor.SuppressDestruct();

  exports.Set("AclasSdk", func);
  return exports;
}

AclasSdk::AclasSdk(const Napi::CallbackInfo& info): Napi::ObjectWrap<AclasSdk>(info) {
  Napi::Env env = info.Env();
  Napi::HandleScope scope(env);
}

Napi::Value AclasSdk::Aclas_Initialize(const Napi::CallbackInfo& info) {
  return Napi::Boolean::New(info.Env(), true);
}

Napi::Value AclasSdk::Aclas_Finalize(const Napi::CallbackInfo& info) {
  return Napi::Number::New(info.Env(), 0);
}

Napi::Value AclasSdk::Aclas_GetInfo(const Napi::CallbackInfo& info) {
  return Napi::String::New(info.Env(), "Boom shakalaka!");
}

Napi::Value AclasSdk::Aclas_ExecTaskWithCB(const Napi::CallbackInfo& info) {
  Napi::Env env = info.Env();
  Napi::Function cb = info[0].As<Napi::Function>();
  cb.Call(env.Global(), {
    Napi::String::New(env, "callback argument 1."),
    Napi::String::New(env, "callback argument 2."),
    Napi::String::New(env, "callback argument 3."),
    Napi::String::New(env, "callback argument 4.")});

  return Napi::Boolean::New(env, true);
}

Napi::Object MountHook(Napi::Env env, Napi::Object exports) {
  return AclasSdk::Init(env, exports);
}

NODE_API_MODULE(aclas_sdk, MountHook)

