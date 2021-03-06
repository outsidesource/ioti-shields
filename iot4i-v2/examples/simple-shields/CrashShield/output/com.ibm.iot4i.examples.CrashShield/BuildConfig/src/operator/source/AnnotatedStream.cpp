// eJyNUl1v2jAUlV_15FbTqAzw0DrTbOm_0dRDcqSvmqkk3aU2SaC7Fw4tTXdLBp_130Xl1JSoW1JHOv6fviccy_0WOrCgpVOmkFqI62Vx74xlLRbSe8aOg4DT59Yl8Cvo_17DD6Lx9u26NB7P_08DaejuOHEEf4fjSI3ozj7sV1p9f91lm8C7LjQ7mm_1XPx1g2_0TCdxFC7jxWpydddZ4913vUn4GE0GSX9040EQIEzuTZ6oKS3jzlUCj1A4TIa9IPtECNFJByfJEsHepIxyhbDorCrmVaPFtHInLdb2e1h1bn3VM8ZzSJXkOEswkxZSTgDUKWYKdIrcozl9bHNYybzUgBzVZt8FfLYSs8gbPJVOssIUEBKQmdIONur6_06bGaJAFmY0Kl_1rRZd1DbbLuqrSASGL4lqjS2B2Ff2rKFLO_0j79qdXqqd1zWhfBl9gUXghQXgiSn34alEE_0iCzHs_0fikGj4H99XXa2yhBXSS5ARZzqHRbH6o_1a4xUn4Ba_1Ys79bLXvoTMnOA2H8NGsuJ4xnbDsFLyVctDV9Nyz6eA8H7ZCi00TwA_0q9JOwWI3B_0gjhQ8


#include "./AnnotatedStream.h"
using namespace SPL::_Operator::source;

#include <SPL/Runtime/Function/SPLFunctions.h>
#include <SPL/Runtime/Operator/Port/Punctuation.h>

#include <string>

#define MY_OPERATOR_SCOPE SPL::_Operator::source
#define MY_BASE_OPERATOR AnnotatedStream_Base
#define MY_OPERATOR AnnotatedStream$OP




void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Tuple const & tuple, uint32_t port) 
{
   IPort0Type const & iport$0 = static_cast<IPort0Type const&>(tuple);
   if (! ((state$_userId != lit$0)) ) 
       return;
   { OPort0Type otuple(state$_userId, iport$0.get_key(), iport$0.get_message()); submit (otuple, 0);
 }
   
}

void MY_OPERATOR_SCOPE::MY_OPERATOR::process(Punctuation const & punct, uint32_t port) 
{
   forwardWindowPunctuation(punct);
}

static SPL::Operator * initer() { return new MY_OPERATOR_SCOPE::MY_OPERATOR(); }
bool MY_BASE_OPERATOR::globalInit_ = MY_BASE_OPERATOR::globalIniter();
bool MY_BASE_OPERATOR::globalIniter() {
    instantiators_.insert(std::make_pair("source::AnnotatedStream",&initer));
    return true;
}

template<class T> static void initRTC (SPL::Operator& o, T& v, const char * n) {
    SPL::ValueHandle vh = v;
    o.getContext().getRuntimeConstantValue(vh, n);
}

MY_BASE_OPERATOR::MY_BASE_OPERATOR()
 : Operator() {
    uint32_t index = getIndex();
    initRTC(*this, lit$0, "lit$0");
    initRTC(*this, lit$1, "lit$1");
    state$_userId = lit$1;
    SPLAPPTRC(L_DEBUG, "Variable: state$_userId Value: " << state$_userId,SPL_OPER_DBG);
    param$filter$0 = (state$_userId != lit$0);
    addParameterValue ("filter", SPL::ConstValueHandle(param$filter$0));
    (void) getParameters(); // ensure thread safety by initializing here
    $oportBitset = OPortBitsetType(std::string("01"));
}
MY_BASE_OPERATOR::~MY_BASE_OPERATOR()
{
    for (ParameterMapType::const_iterator it = paramValues_.begin(); it != paramValues_.end(); it++) {
        const ParameterValueListType& pvl = it->second;
        for (ParameterValueListType::const_iterator it2 = pvl.begin(); it2 != pvl.end(); it2++) {
            delete *it2;
        }
    }
}

void MY_BASE_OPERATOR::tupleLogic(Tuple const & tuple, uint32_t port) {
    IPort0Type const & iport$0 = static_cast<IPort0Type const  &>(tuple);
    AutoPortMutex $apm($svMutex, *this);
    
{
    state$_userId = ::SPL::JNIFunctions::com::ibm::iot4i::events::MH::SPL_JNIFunctions::getUserId(iport$0.get_message());
}

}


void MY_BASE_OPERATOR::processRaw(Tuple const & tuple, uint32_t port) {
    tupleLogic (tuple, port);
    static_cast<MY_OPERATOR_SCOPE::MY_OPERATOR*>(this)->MY_OPERATOR::process(tuple, port);
}


void MY_BASE_OPERATOR::punctLogic(Punctuation const & punct, uint32_t port) {
}

void MY_BASE_OPERATOR::punctPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    {
        punctNoPermitProcessRaw(punct, port);
    }
}

void MY_BASE_OPERATOR::punctNoPermitProcessRaw(Punctuation const & punct, uint32_t port) {
    switch(punct) {
    case Punctuation::WindowMarker:
        punctLogic(punct, port);
        process(punct, port);
        break;
    case Punctuation::FinalMarker:
        punctLogic(punct, port);
        
        if (punct == Punctuation::FinalMarker) {
            process(punct, port);
            bool forward = false;
            {
                AutoPortMutex $apm($fpMutex, *this);
                $oportBitset.reset(port);
                if ($oportBitset.none()) {
                    $oportBitset.set(1);
                    forward=true;
                }
            }
            if(forward)
                submit(punct, 0);
            return;
        }
        process(punct, port);
        break;
    case Punctuation::DrainMarker:
    case Punctuation::ResetMarker:
    case Punctuation::ResumeMarker:
        break;
    case Punctuation::SwitchMarker:
        break;
    default:
        break;
    }
}

void MY_BASE_OPERATOR::processRaw(Punctuation const & punct, uint32_t port) {
    switch(port) {
    case 0:
        punctNoPermitProcessRaw(punct, port);
        break;
    }
}



void MY_BASE_OPERATOR::checkpointStateVariables(NetworkByteBuffer & opstate) const {
    opstate << state$_userId;
}

void MY_BASE_OPERATOR::restoreStateVariables(NetworkByteBuffer & opstate) {
    opstate >> state$_userId;
}

void MY_BASE_OPERATOR::checkpointStateVariables(Checkpoint & ckpt) {
    ckpt << state$_userId;
}

void MY_BASE_OPERATOR::resetStateVariables(Checkpoint & ckpt) {
    ckpt >> state$_userId;
}

void MY_BASE_OPERATOR::resetStateVariablesToInitialState() {
    state$_userId = lit$1;
    SPLAPPTRC(L_DEBUG, "Variable: state$_userId Value: " << state$_userId,SPL_OPER_DBG);
}

bool MY_BASE_OPERATOR::hasStateVariables() const {
    return true;
}

void MY_BASE_OPERATOR::resetToInitialStateRaw() {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->resetToInitialState();
    }
    resetStateVariablesToInitialState();
}

void MY_BASE_OPERATOR::checkpointRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->checkpoint(ckpt);
    }
    checkpointStateVariables(ckpt);
}

void MY_BASE_OPERATOR::resetRaw(Checkpoint & ckpt) {
    AutoMutex $apm($svMutex);
    StateHandler *sh = getContext().getStateHandler();
    if (sh != NULL) {
        sh->reset(ckpt);
    }
    resetStateVariables(ckpt);
}



