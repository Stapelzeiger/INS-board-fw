#include <CppUTest/TestHarness.h>
#include <CppUTestExt/MockSupport.h>
#include "../messagebus.h"
#include "mocks/synchronization.hpp"
#include "types/test.h"


TEST_GROUP(MessageBusAtomicityTestGroup)
{
    msgbus_t bus;
    msgbus_topic_t topic;
    uint8_t buffer[128];

    void setup()
    {
        mock().strictOrder();

        messagebus_init(&bus);
        messagebus_topic_create(&topic, &bus, &simple_type, buffer, "topic");
    }

    void teardown()
    {
        lock_mocks_enable(false);
        mock().checkExpectations();
        mock().clear();
    }
};

TEST(MessageBusAtomicityTestGroup, AdvertiseIsLockedProperly)
{
    mock().expectOneCall("messagebus_lock_acquire")
          .withPointerParameter("lock", &bus.lock);
    mock().expectOneCall("messagebus_lock_release")
          .withPointerParameter("lock", &bus.lock);

    lock_mocks_enable(true);
    messagebus_init(&bus);
    messagebus_topic_create(&topic, &bus, &simple_type, buffer, "topic");
}

TEST(MessageBusAtomicityTestGroup, FindNoneIsLockedProperly)
{
    mock().expectOneCall("messagebus_lock_acquire")
          .withPointerParameter("lock", &bus.lock);
    mock().expectOneCall("messagebus_lock_release")
          .withPointerParameter("lock", &bus.lock);

    lock_mocks_enable(true);
    messagebus_find_topic(&bus, "topic");
}

TEST(MessageBusAtomicityTestGroup, FindExistingTopicIsLockedProperly)
{
    mock().expectOneCall("messagebus_lock_acquire")
          .withPointerParameter("lock", &bus.lock);
    mock().expectOneCall("messagebus_lock_release")
          .withPointerParameter("lock", &bus.lock);

    lock_mocks_enable(true);
    messagebus_find_topic(&bus, "topic");
}

TEST(MessageBusAtomicityTestGroup, PublishIsAtomic)
{
    uint8_t data[4];
    mock().expectOneCall("messagebus_lock_acquire")
          .withPointerParameter("lock", &topic.lock);
    mock().expectOneCall("messagebus_lock_release")
          .withPointerParameter("lock", &topic.lock);

    lock_mocks_enable(true);
    messagebus_topic_publish(&topic, data);
}

TEST(MessageBusAtomicityTestGroup, ReadPublished)
{
    uint8_t buffer[128];
    bool res;

    mock().expectOneCall("messagebus_lock_acquire")
          .withPointerParameter("lock", &topic.lock);
    mock().expectOneCall("messagebus_lock_release")
          .withPointerParameter("lock", &topic.lock);

    messagebus_topic_publish(&topic, buffer);

    lock_mocks_enable(true);
    res = messagebus_topic_read(&topic, buffer);

    CHECK_TRUE(res);
}

TEST(MessageBusAtomicityTestGroup, ReadUnpublished)
{
    uint8_t buffer[128];
    bool res;
    mock().expectOneCall("messagebus_lock_acquire")
          .withPointerParameter("lock", &topic.lock);
    mock().expectOneCall("messagebus_lock_release")
          .withPointerParameter("lock", &topic.lock);

    lock_mocks_enable(true);
    res = messagebus_topic_read(&topic, buffer);

    CHECK_FALSE(res);
}

TEST(MessageBusAtomicityTestGroup, Wait)
{
    uint8_t buffer[128];
    mock().expectOneCall("messagebus_lock_acquire")
          .withPointerParameter("lock", &topic.lock);
    mock().expectOneCall("messagebus_lock_release")
          .withPointerParameter("lock", &topic.lock);

    lock_mocks_enable(true);
    messagebus_topic_wait(&topic, buffer);
}

TEST(MessageBusAtomicityTestGroup, FindBlocking)
{
    lock_mocks_enable(true);

    mock().expectOneCall("messagebus_lock_acquire")
          .withPointerParameter("lock", &bus.lock);

    mock().expectOneCall("messagebus_lock_release")
          .withPointerParameter("lock", &bus.lock);

    messagebus_find_topic_blocking(&bus, "topic");
}
