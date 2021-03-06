/**
 * @file <argos3/plugins/simulator/entities/radio_equipped_entity.h>
 *
 * @author Michael Allwright - <allsey87@gmail.com>
 */

#ifndef RADIO_EQUIPPED_ENTITY_H
#define RADIO_EQUIPPED_ENTITY_H

namespace argos {
   class CRadioEquippedEntity;
   class CRadioEntity;
}

#include <argos3/core/simulator/entity/composable_entity.h>
#include <argos3/plugins/simulator/entities/radio_entity.h>
#include <vector>

namespace argos {

   /**
    * A container of CRadioEntity.
    * <p>
    * This is a convenience class that acts a container of CRadioEntity objects.
    * It is mostly useful when a robot is equipped with a number of radios, and you
    * want to manage them comfortably.
    * </p>
    * @see CRadioEntity
    */
   class CRadioEquippedEntity : public CComposableEntity {

   public:

      ENABLE_VTABLE();

   public:

      struct SInstance {
         CRadioEntity& Radio;
         SAnchor& Anchor;
         CVector3 Offset;
         SInstance(CRadioEntity& c_radio,
                   SAnchor& s_anchor,
                   const CVector3& c_offset);
         using TVector = std::vector<SInstance>;         
      };

   public:

      /**
       * Class constructor.
       * @param pc_parent The parent entity.
       */
      CRadioEquippedEntity(CComposableEntity* pc_parent);

      /**
       * Class constructor.
       * @param pc_parent The parent entity.
       * @param str_id The id of this entity.
       */
      CRadioEquippedEntity(CComposableEntity* pc_parent,
                         const std::string& str_id);

      virtual ~CRadioEquippedEntity() {}

      virtual void Init(TConfigurationNode& t_tree);

      virtual void Reset();

      virtual void Enable();

      virtual void Disable();

      /**
       * Returns a radio by numeric index.
       * @param un_index The index of the specified radio.
       * @return A radio by numeric index.
       * @see GetInstances()
       */
      CRadioEntity& GetRadio(UInt32 un_index);

      /**
       * Returns the radios.
       * @return The radios.
       * @see GetInstances()
       * @see GetRadio()
       */
      inline SInstance::TVector& GetInstances() {
         return m_vecInstances;
      }

      /**
       * Returns the radios as a const reference.
       * @return The radios as a const reference.
       * @see GetInstances()
       * @see GetRadio()
       */
      inline const SInstance::TVector& GetInstances() const {
         return m_vecInstances;
      }

      /**
       * Adds the radios to the specified radio medium.
       * @param c_medium The radio medium.
       * @see CRadioMedium
       */
      void AddToMedium(CRadioMedium& c_medium);

      /**
       * Removes the radios from the associated radio medium.
       * @see CRadioMedium
       */
      void RemoveFromMedium();

      virtual std::string GetTypeDescription() const {
         return "radios";
      }

   protected:

      virtual void UpdateComponents();

   protected:

      /** List of the radios managed by this entity */
      SInstance::TVector m_vecInstances;
   };

}

#endif
