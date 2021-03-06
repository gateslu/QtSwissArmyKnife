﻿/*
 * Copyright 2018-2020 Qter(qsak@foxmail.com). All rights reserved.
 *
 * The file is encoding with utf-8 (with BOM). It is a part of QtSwissArmyKnife
 * project(https://www.qsak.pro). The project is an open source project. You can
 * get the source of the project from: "https://github.com/qsak/QtSwissArmyKnife"
 * or "https://gitee.com/qsak/QtSwissArmyKnife". Also, you can join in the QQ
 * group which number is 952218522 to have a communication.
 */
#include <QDebug>
#include <QWidget>
#include <QHBoxLayout>

#include "SAKGlobal.hh"
#include "SAKDataStruct.hh"
#include "SAKSctpClientDevice.hh"
#include "SAKSctpClientDebugPage.hh"
#include "SAKSctpClientDeviceController.hh"

SAKSctpClientDebugPage::SAKSctpClientDebugPage(QWidget *parent)
    :SAKDebugPage (SAKDataStruct::DebugPageTypeTCPClient, parent)
    ,tcpClientDeviceController (new SAKSctpClientDeviceController)
{
    initPage();
    setWindowTitle(SAKGlobal::debugPageNameFromType(SAKDataStruct::DebugPageTypeTCPClient));
}

SAKSctpClientDebugPage::~SAKSctpClientDebugPage()
{
    tcpClientDeviceController->deleteLater();
}

SAKSctpClientDeviceController *SAKSctpClientDebugPage::controllerInstance()
{
    return tcpClientDeviceController;
}

void SAKSctpClientDebugPage::refreshDevice()
{
    tcpClientDeviceController->refresh();
}

QWidget *SAKSctpClientDebugPage::controllerWidget()
{
    return tcpClientDeviceController;
}

SAKDevice *SAKSctpClientDebugPage::createDevice()
{
    SAKSctpClientDevice *device = new SAKSctpClientDevice(this);
    return device;
}

void SAKSctpClientDebugPage::setUiEnable(bool enable)
{
    tcpClientDeviceController->setEnabled(enable);
    refreshPushButton->setEnabled(enable);
}
