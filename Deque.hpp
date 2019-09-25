#ifndef  MYDEQUE

#define MYDEQUE
#define MAX 100

#define mkarr(type) (type*)(malloc(sizeof(type[MAX])))

#define INIT(type) {-1,0,MAX,mkarr(type),get_size_##type,push_back_##type,push_front_##type,is_Full_##type,is_Empty_##type,get_front_##type,get_rear_##type,pop_front_##type,pop_back_##type,at_##type}


#define Deque_DEFINE(type)            \
struct Deque_##type;                                                  \
typedef struct Deque_##type##_Iterator{                               \
type *itr;/*point to object in deque*/                                \
int cur_itr_idx;                                                          \
int fi;                                                               \
int li;                                                               \
int capacity;                                                         \
void (*inc)(Deque_##type##_Iterator * itr);                           \
void (*dec)(Deque_##type##_Iterator * itr);                             \
type& (*deref)(Deque_##type##_Iterator * it); \
Deque_##type *deq;                          \
}Deque_##type##_Iterator;                                              \
                                                                      \
typedef struct Deque_##type{                                          \
int begin_idx;                                                        \
int end_idx;                                                          \
int length;                                                           \
type *arr;/*/ this(type) need to come from the user/*/                \
size_t (*size)(Deque_##type *dq);                                        \
/*/ here come the function pointers*/                                 \
void (*push_back)(Deque_##type *dq,type);/*come from user*/           \
void (*push_front)(Deque_##type *dq,type);                            \
bool (*is_Full)(Deque_##type *dq);                                    \
bool (*empty)(Deque_##type *dq);                                      \
type &(*front)(Deque_##type *dq);/*type in macro*/                    \
type &(*back)(Deque_##type *dq);/*type in macro*/                     \
type (*pop_front)(Deque_##type *dq);                                  \
type (*pop_back)(Deque_##type *dq);                                   \
type &(*at)(Deque_##type *dq, int i);                                 \
void (*dtor)(Deque_##type *dq);                                       \
void (*clear)(Deque_##type *dq);                                      \
Deque_##type##_Iterator (*begin)(Deque_##type *dq);                   \
Deque_##type##_Iterator (*end)(Deque_##type *dq);                     \
bool (*type##_comp)(const type& o1, const type& o2);            \
const char type_name[sizeof("Deque_"#type)]="Deque_"#type;\
void (*sort)(Deque_##type *d,Deque_##type##_Iterator d2,Deque_##type##_Iterator d3);          \
}Deque_##type;                                                        \
bool is_Full_##type(Deque_##type *dq){                                \
  return ((dq->begin_idx==0 && dq->end_idx==dq->length-1)||(dq->begin_idx==dq->end_idx+1)); \
}                                                                    \
bool is_Empty_##type(Deque_##type *dq){                              \
  return(dq->end_idx==-1);                                         \
  }                                                                  \
                                                                     \
size_t get_size_##type (Deque_##type *dq){                              \
  if(dq->begin_idx ==-1 && dq->end_idx==-1){return 0;}                \
  else if(dq->begin_idx==dq->end_idx){return 1;}                     \
  else if(dq->begin_idx < dq->end_idx){return ((dq->end_idx)-(dq->begin_idx))+1;} \
  else {return dq->length-((dq->begin_idx - dq->end_idx)-1);}\
}                                                                 \
/*/ADD REAR*/                                                       \
void push_back_##type (Deque_##type *dq,type key){                  \
      int capacity=dq->length;                                      \
      if(dq->is_Full(dq)){                                          \
        dq->length=dq->length*2;                                    \
        dq->arr=(type*)realloc(dq->arr,dq->length*sizeof(type));    \
        /*std::cout<<"array expanded"<<std::endl;*/                  \
        if(dq->begin_idx>dq->end_idx){                              \
        for(int i = 0; i<dq->begin_idx; i++) {                      \
            dq->arr[i+capacity] = dq->arr[i];                       \
        }                                                           \
        dq->end_idx = dq->end_idx + capacity;                       \
        }                                                           \
      }                                                             \
      if(dq->begin_idx==-1){                                        \
      dq->begin_idx=0;                                              \
      dq->end_idx=0;                                                \
      }                                                             \
      else if(dq->end_idx==dq->length-1){                           \
      dq->end_idx = 0;                                              \
      }else{                                                        \
      dq->end_idx++;                                                \
      }                                                             \
      /* add key to the array*/                                     \
      dq->arr[dq->end_idx]=key;                                     \
}                                                                   \
/* ADD FRONT*/                                                      \
void push_front_##type (Deque_##type *dq,type key){                 \
      int capacity=dq->length;                                      \
      if(dq->is_Full(dq)){                                          \
        dq->length=dq->length*2;                                    \
        dq->arr=(type*)realloc(dq->arr,dq->length*sizeof(type));    \
        /*std::cout<<"array expanded"<<std::endl; */                \
        if(dq->begin_idx>dq->end_idx){                              \
        for(int i = 0; i<dq->begin_idx; i++) {                      \
            dq->arr[i+capacity] = dq->arr[i];                       \
        }                                                           \
        dq->end_idx = dq->end_idx + capacity;                       \
        /*std::cout<<"executed"<<std::endl;*/                       \
        }                                                           \
      }                                                             \
    if(dq->begin_idx==-1){                                          \
      dq->begin_idx=0;                                              \
      dq->end_idx=0;                                                \
    }else if(dq->begin_idx==0){                                     \
      dq->begin_idx=dq->length-1;                                   \
    }                                                         \
    else{                                                     \
      dq->begin_idx--;                                            \
    }                                                         \
    dq->arr[dq->begin_idx]=key;                                   \
}                                                             \
/*/GET REAR*/                                                 \
type &get_rear_##type (Deque_##type *dq){                      \
  if(dq->empty(dq)){                                       \
    std::cout<< "Queue underflow";                                 \
                                                    \
  }                                                           \
  return dq->arr[dq->end_idx];                                   \
}                                                             \
/*/GET FRONT*/                                                \
type &get_front_##type (Deque_##type *dq){                     \
  if(dq->empty(dq)){                                       \
    std::cout<< "Queue underflow";                                 \
                                                              \
  }                                                           \
  return dq->arr[dq->begin_idx];                                  \
}                                                              \
type &at_##type(Deque_##type *dq, int i){                       \
if(dq->empty(dq)){std::cout<<"Queue underflow";}                \
return dq->arr[(dq->begin_idx+i) % dq->length];                                                             \
}                                                           \
/*DELETE REAR*/                                               \
type pop_back_##type(Deque_##type *dq){                       \
  int ret=dq->end_idx;                                           \
  if (dq->empty(dq))                                       \
  {                                                           \
    std::cout << " bUnderflow\n" << std::endl ;               \
                                                  \
  }                                                           \
if(dq->begin_idx==dq->end_idx){                                      \
  dq->end_idx = -1;                                              \
  dq->begin_idx = -1;                                             \
}else if(dq->end_idx==0){                                           \
  dq->end_idx = dq->length-1;                                       \
}                                                               \
else{                                                           \
  dq->end_idx--;                                                    \
}                                                               \
return (dq->arr[ret]);                                          \
}                                                               \
/*DELETE FRONT*/                                                \
type pop_front_##type (Deque_##type *dq){                       \
  int ret =dq->begin_idx;                                           \
  if (dq->empty(dq))                                         \
  {                                                             \
    std::cout << " fUnderflow\n" << std::endl ;                 \
                                                                \
  }                                                             \
  if(dq->begin_idx==dq->end_idx){                               \
    dq->end_idx = -1;                                           \
    dq->begin_idx =-1;                                          \
  }                                                             \
  else{                                                         \
     if(dq->begin_idx==(dq->length)-1){                         \
       dq->begin_idx = 0;                                       \
     }else{                                                     \
       dq->begin_idx++;                                         \
     }                                                          \
  }                                                             \
  return (dq->arr[ret]);                                        \
}                                                               \
void destructor_##type(Deque_##type *dq){                       \
            free (dq->arr);                                     \
}                                                               \
void clear_##type(Deque_##type *dq){                            \
 memset(dq->arr,0,dq->length*sizeof(dq->arr[0]));               \
dq->begin_idx=-1;                                               \
 dq->end_idx=0;                                                 \
}                                                               \
void inc_##type(Deque_##type##_Iterator *itr){ \
                  \
    if(itr->cur_itr_idx <= itr->li){itr->itr++; itr->cur_itr_idx++; }   \
    else if(itr->cur_itr_idx > itr->li){                            \
      if(itr->cur_itr_idx==itr->capacity-1){                    \
        itr->itr= itr->itr - itr->capacity;                     \
        itr->cur_itr_idx=0;                                     \
      }                                                         \
      itr->itr++; itr->cur_itr_idx++;                        \
      }                                                         \
      \
}                                                               \
void dec_##type(Deque_##type##_Iterator *itr){                     \
                                                                  \
    if(itr->cur_itr_idx >= itr->fi){itr->itr--; itr->cur_itr_idx--;}\
    else if(itr->cur_itr_idx < itr->fi){\
    if(itr->cur_itr_idx==0){\
    itr->itr = itr->itr+itr->capacity;\
    }\
    itr->itr--; itr->cur_itr_idx--;\
    } \
}                                                               \
type& deref_##type(Deque_##type##_Iterator* iter){              \
    return *(iter->itr);                                          \
  }                                                             \
Deque_##type##_Iterator begin_##type(Deque_##type * dq){        \
      type * begin_idx = &dq->arr[dq->begin_idx];                  \
      Deque_##type##_Iterator it = {begin_idx,dq->begin_idx,dq->begin_idx,dq->end_idx,dq->length, inc_##type, dec_##type,deref_##type,dq}; \
      return it;                                                \
}                                                                 \
Deque_##type##_Iterator end_##type(Deque_##type * dq){        \
      type *end_idx = &dq->arr[dq->end_idx]+1;                  \
      Deque_##type##_Iterator it = {end_idx,dq->end_idx,dq->begin_idx,dq->end_idx,dq->length, inc_##type, dec_##type,deref_##type,dq};\
      return it;                                                \
}                                                               \
bool Deque_##type##_equal(Deque_##type dq1, Deque_##type dq2){  \
if(dq1.size(&dq1) != dq2.size(&dq2)){\
return false;\
}\
for(int i = 0; i < dq1.size(&dq1); i++){\
type& dq1_element = dq1.at(&dq1, i);\
type& dq2_element = dq2.at(&dq2, i);\
if(dq1.type##_comp(dq1_element, dq2_element) || (dq1.type##_comp(dq2_element, dq1_element))){\
return false;\
}\
}\
return true;\
}                                                               \
int adapter_##type(const void *vp1, const void *vp2, void *vp){ \
  auto cfp = (bool(*)(const type *,const type *))vp;            \
  type *pp1 = (type *) vp1;                                     \
  type *pp2 = (type *) vp2;                                     \
  if ((*cfp)(pp1,pp2)) {                                        \
    return -1;                                                  \
  } else if ((*cfp)(pp2,pp1)){                                  \
    return 1;                                                   \
  } else {                                                      \
    return 0;                                                   \
  }                                                             \
}     \
void sort_##type(Deque_##type *d,Deque_##type##_Iterator i1,Deque_##type##_Iterator i2){     \
if(i1.cur_itr_idx < i2.cur_itr_idx){\
qsort_r(&d->arr[i1.cur_itr_idx],i2.cur_itr_idx-i1.cur_itr_idx+1,sizeof(type),adapter_##type,(void *)d->type##_comp) ; \
}\
}\
bool Deque_##type##_Iterator_equal(Deque_##type##_Iterator iter1,Deque_##type##_Iterator iter2){\
return (!(iter1.deq->type##_comp(*iter1.itr, *iter2.itr)) && !(iter1.deq->type##_comp(*iter2.itr, *iter1.itr)));\
} \
void Deque_##type##_ctor(Deque_##type *dq, bool (*fpr)(const type& a,const type& b)){\
 dq->begin_idx=-1;\
 dq->end_idx=-1;\
 dq->length=MAX;\
 dq->arr=mkarr(type);\
 dq->size=get_size_##type;\
 dq->push_back= push_back_##type;\
 dq->push_front=push_front_##type;\
 dq->is_Full = is_Full_##type;\
 dq->empty = is_Empty_##type;\
 dq->front = get_front_##type;\
 dq->back = get_rear_##type;\
 dq->pop_front = pop_front_##type;\
 dq->pop_back = pop_back_##type;\
 dq->at = at_##type;\
 dq->dtor = destructor_##type;\
 dq->clear = clear_##type;\
 dq->begin = begin_##type;\
 dq->end = end_##type;\
 dq->type##_comp = fpr;\
 dq->sort=sort_##type;\
 }\

#endif
