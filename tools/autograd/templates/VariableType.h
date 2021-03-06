#pragma once

// ${generated_comment}

#include <ATen/ATen.h>

#include <ATen/TypeDefault.h>

#include <torch/csrc/WindowsTorchApiMacro.h>

#include <cstdint> // for size_t
#include <functional> // for function
#include <memory> // for unique_ptr
#include <string>
#include <vector>

namespace torch { namespace autograd {

struct Variable;
using at::Context;
using at::Generator;
using at::IntList;
using at::Scalar;
using at::SparseTensorRef;
using at::ScalarType;
using at::Storage;
using at::Tensor;
using at::TensorList;
using at::Type;
using at::ScalarType;
using at::optional;
using at::Device;

void register_variable_type_for(at::TypeExtendedInterface* baseType);

struct TORCH_API VariableType final : public at::TypeDefault {
  VariableType(Context* context, at::TypeExtendedInterface* baseType);
  at::ScalarType scalarType() const override;
  virtual caffe2::TypeMeta typeMeta() const override;
  at::Backend backend() const override;
  at::Allocator* allocator() const override;
  at::Device getDeviceFromPtr(void * data) const override;
  Storage storage(bool resizable = false) const override;
  Storage storage(size_t size, bool resizable = false) const override;
  Storage storageFromBlob(void * data, int64_t size, const std::function<void(void*)> & deleter) const override;
  Storage storageWithAllocator(int64_t size, at::Allocator* allocator) const override;
  std::unique_ptr<at::Generator> generator() const override;
  const char * toString() const override;
  at::TypeID ID() const override;
  size_t elementSizeInBytes() const override;
  at::Type & toBackend(at::Backend b) const override;
  at::Type & toScalarType(at::ScalarType s) const override;
  Storage unsafeStorageFromTH(void * th_pointer, bool retain) const override;
  at::Tensor unsafeTensorFromTH(void * th_pointer, bool retain) const override;

  static at::TypeExtendedInterface* getVariableTypeFromBaseType(const at::Type& baseType);
  static bool isVariableType(const at::Type& type);
  static std::vector<at::Type*> allCUDATypes();
  static std::vector<at::Type*> allCPUTypes();

  Tensor & s_copy_(Tensor & self, const Tensor & src, bool non_blocking) const override;
  Tensor & _s_copy_from(const Tensor & self, Tensor & dst, bool non_blocking) const override;

  void backward(Tensor & self, at::optional<Tensor> gradient, bool keep_graph, bool create_graph) const override;
  void set_data(Tensor & self, Tensor new_data) const override;

  ${type_derived_method_declarations}

private:
  // checks that t is actually a Variable
  static Variable & checked_cast_variable(const Tensor & t, const char * name, int pos);
  static at::Tensor & unpack(const Tensor & t, const char * name, int pos);
  static at::SparseTensorRef unpack(SparseTensorRef t, const char * name, int pos);
  static at::Tensor unpack_opt(const Tensor & t, const char * name, int pos);
  static std::vector<at::Tensor> unpack(at::TensorList tl, const char *name, int pos);

  at::TypeExtendedInterface* baseType;
  std::string str;
  size_t id_;
};

}} // namespace torch::autograd
