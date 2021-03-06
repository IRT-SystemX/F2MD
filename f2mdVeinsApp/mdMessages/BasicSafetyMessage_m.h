//
// Generated file, do not edit! Created by nedtool 5.4 from veins/modules/application/f2mdVeinsApp/mdMessages/BasicSafetyMessage.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __VEINS_BASICSAFETYMESSAGE_M_H
#define __VEINS_BASICSAFETYMESSAGE_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0504
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
#include "veins/base/utils/Coord.h"
#include "veins/modules/messages/BaseFrame1609_4_m.h"
#include "veins/base/utils/SimpleAddress.h"
// }}


namespace Veins {

/**
 * Class generated from <tt>veins/modules/application/f2mdVeinsApp/mdMessages/BasicSafetyMessage.msg:33</tt> by nedtool.
 * <pre>
 * packet BasicSafetyMessage extends BaseFrame1609_4
 * {
 *     Coord senderPos;
 *     Coord senderPosConfidence;
 *     Coord senderSpeed;
 *     Coord senderSpeedConfidence;
 *     Coord senderHeading;
 *     Coord senderHeadingConfidence;
 *     double senderWidth;
 *     double senderLength;
 *     int senderMbType;
 *     int senderAttackType;
 *     Coord senderGpsCoordinates;
 *     unsigned long senderPseudonym;
 * }
 * </pre>
 */
class BasicSafetyMessage : public ::Veins::BaseFrame1609_4
{
  protected:
    Coord senderPos;
    Coord senderPosConfidence;
    Coord senderSpeed;
    Coord senderSpeedConfidence;
    Coord senderHeading;
    Coord senderHeadingConfidence;
    double senderWidth;
    double senderLength;
    int senderMbType;
    int senderAttackType;
    Coord senderGpsCoordinates;
    unsigned long senderPseudonym;

  private:
    void copy(const BasicSafetyMessage& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const BasicSafetyMessage&);

  public:
    BasicSafetyMessage(const char *name=nullptr, short kind=0);
    BasicSafetyMessage(const BasicSafetyMessage& other);
    virtual ~BasicSafetyMessage();
    BasicSafetyMessage& operator=(const BasicSafetyMessage& other);
    virtual BasicSafetyMessage *dup() const override {return new BasicSafetyMessage(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual Coord& getSenderPos();
    virtual const Coord& getSenderPos() const {return const_cast<BasicSafetyMessage*>(this)->getSenderPos();}
    virtual void setSenderPos(const Coord& senderPos);
    virtual Coord& getSenderPosConfidence();
    virtual const Coord& getSenderPosConfidence() const {return const_cast<BasicSafetyMessage*>(this)->getSenderPosConfidence();}
    virtual void setSenderPosConfidence(const Coord& senderPosConfidence);
    virtual Coord& getSenderSpeed();
    virtual const Coord& getSenderSpeed() const {return const_cast<BasicSafetyMessage*>(this)->getSenderSpeed();}
    virtual void setSenderSpeed(const Coord& senderSpeed);
    virtual Coord& getSenderSpeedConfidence();
    virtual const Coord& getSenderSpeedConfidence() const {return const_cast<BasicSafetyMessage*>(this)->getSenderSpeedConfidence();}
    virtual void setSenderSpeedConfidence(const Coord& senderSpeedConfidence);
    virtual Coord& getSenderHeading();
    virtual const Coord& getSenderHeading() const {return const_cast<BasicSafetyMessage*>(this)->getSenderHeading();}
    virtual void setSenderHeading(const Coord& senderHeading);
    virtual Coord& getSenderHeadingConfidence();
    virtual const Coord& getSenderHeadingConfidence() const {return const_cast<BasicSafetyMessage*>(this)->getSenderHeadingConfidence();}
    virtual void setSenderHeadingConfidence(const Coord& senderHeadingConfidence);
    virtual double getSenderWidth() const;
    virtual void setSenderWidth(double senderWidth);
    virtual double getSenderLength() const;
    virtual void setSenderLength(double senderLength);
    virtual int getSenderMbType() const;
    virtual void setSenderMbType(int senderMbType);
    virtual int getSenderAttackType() const;
    virtual void setSenderAttackType(int senderAttackType);
    virtual Coord& getSenderGpsCoordinates();
    virtual const Coord& getSenderGpsCoordinates() const {return const_cast<BasicSafetyMessage*>(this)->getSenderGpsCoordinates();}
    virtual void setSenderGpsCoordinates(const Coord& senderGpsCoordinates);
    virtual unsigned long getSenderPseudonym() const;
    virtual void setSenderPseudonym(unsigned long senderPseudonym);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const BasicSafetyMessage& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, BasicSafetyMessage& obj) {obj.parsimUnpack(b);}

} // namespace Veins

#endif // ifndef __VEINS_BASICSAFETYMESSAGE_M_H

