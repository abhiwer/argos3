/**
 * @file <argos3/core/simulator/entity/medium_entity.cpp>
 *
 * @author Carlo Pinciroli - <ilpincy@gmail.com>
 */

#include "medium_entity.h"

namespace argos {

   /****************************************/
   /****************************************/

   CMediumEntity::CMediumEntity() :
      CEntity(NULL) {}

   /****************************************/
   /****************************************/

   CMediumEntity::CMediumEntity(const std::string& str_id) :
      CEntity(NULL, str_id) {}

   /****************************************/
   /****************************************/

}
