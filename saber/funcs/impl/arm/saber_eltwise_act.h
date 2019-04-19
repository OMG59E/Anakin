/* Copyright (c) 2018 Anakin Authors, Inc. All Rights Reserved.
   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

#ifndef ANAKIN_SABER_FUNCS_IMPL_ARM_SABER_ELTWISE_ACT_H
#define ANAKIN_SABER_FUNCS_IMPL_ARM_SABER_ELTWISE_ACT_H

#include "saber/funcs/impl/impl_eltwise_act.h"

namespace anakin{

namespace saber{

template <DataType OpDtype>
class SaberEltwiseActive<ARM, OpDtype> : \
    public ImplBase<
        ARM,
        OpDtype,
        EltwiseActiveParam<ARM> >
{
public:
    typedef typename DataTrait<ARM, OpDtype>::Dtype OpDataType;
    typedef void (*eltwise_act_func)(const float* din_a, \
        const float* din_b, float* dout, const int num, const int channel, \
        const int channel_size, std::vector<float> coef, bool channel_shared, const float* slop_ptr);

    SaberEltwiseActive()
    {}

    ~SaberEltwiseActive() {}

    virtual SaberStatus init(const std::vector<Tensor<ARM> *>& inputs,
                      std::vector<Tensor<ARM> *>& outputs,
                      EltwiseActiveParam<ARM> &param, Context<ARM> &ctx){
        this->_ctx = &ctx;
        return create(inputs, outputs, param, ctx);
    }

    virtual SaberStatus create(const std::vector<Tensor<ARM> *>& inputs,
                            std::vector<Tensor<ARM> *>& outputs,
                            EltwiseActiveParam<ARM>& param, Context<ARM> &ctx);

    virtual SaberStatus dispatch(const std::vector<Tensor<ARM> *>& inputs,
                          std::vector<Tensor<ARM> *>& outputs,
                          EltwiseActiveParam<ARM>& param);
private:
    eltwise_act_func _impl{nullptr};

};

}

}
#endif //ANAKIN_SABER_FUNCS_IMPL_ARM_SABER_ELTWISE_ACT_H
