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

#ifndef ANAKIN_OPERATOR_PS_ROI_POOLING_H
#define ANAKIN_OPERATOR_PS_ROI_POOLING_H

#include "framework/core/base.h"
#include "framework/core/data_types.h"
#include "framework/core/operator/operator.h"
#include "utils/logger/logger.h"
#include "saber/funcs/ps_roi_pooling.h"

namespace anakin {

namespace ops {

template<typename Ttype, Precision Ptype>
class PsRoiPoolingHelper;

/// PsRoiPooling op
/**
 * \brief PsRoiPooling implementation class
 * public inherit Operator
 */
template<typename Ttype, Precision Ptype>
class PsRoiPooling : public Operator<Ttype, Ptype> {
public:
    PsRoiPooling() {}

    /// forward impl
    virtual void operator() (OpContext<Ttype> &ctx, 
                             const std::vector<Tensor4dPtr<Ttype> >& ins, 
                             std::vector<Tensor4dPtr<Ttype> >& outs) {
		LOG(ERROR) << "Not Impl Yet Operator PsRoiPooling< Ttype("
				   << target_name<Ttype>::value << "), Precision("<< Ptype <<") >";	

    }

    friend class PsRoiPoolingHelper<Ttype, Ptype>;
};

/**
 * \brief PsRoiPooling helper class to implement PsRoiPooling 
 * public inherit OperatorHelper
 * including init resource and shape size in PsRoiPooling context
 */
template<typename Ttype, Precision Ptype>
class PsRoiPoolingHelper : public OperatorHelper<Ttype, Ptype> {
public:
    PsRoiPoolingHelper()=default;

    ~PsRoiPoolingHelper() {}

    Status InitParam() override;

    /**
    * \brief initial all the resource needed by PsRoiPooling
    * \param ctx stand for PsRoiPooling operation context
    * \param ins stand for input tensor vector
    * \param outs stand for output tensor vector
    * \return status
    */
    Status Init(OpContext<Ttype> &ctx,
                const std::vector<Tensor4dPtr<Ttype> >& ins, 
                std::vector<Tensor4dPtr<Ttype> >& outs) override;

    /**
    * \brief infer the shape of output and input.
    * \param ins stand for input tensor vector
    * \param outs stand for output tensor vector
    * \return status
    */
    Status InferShape(const std::vector<Tensor4dPtr<Ttype> >& ins,
                      std::vector<Tensor4dPtr<Ttype> >& outs) override;

public:
    ///< _param_PsRoiPooling stand for PsRoiPooling parameter
    saber::PsRoiPoolParam<Ttype> _param_ps_roi_pooling;
    ///< _funcs_PsRoiPooling stand for PsRoiPooling function
    saber::PsRoiPool<Ttype, PrecisionWrapper<Ptype>::saber_type> _funcs_ps_roi_pooling;
};


} /* namespace ops */

} /* namespace anakin */

#endif
