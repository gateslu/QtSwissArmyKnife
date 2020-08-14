﻿/*
 * Copyright 2018-2020 Qter(qsaker@qq.com). All rights reserved.
 *
 * The file is encoded using "utf8 with bom", it is a part
 * of QtSwissArmyKnife project.
 *
 * QtSwissArmyKnife is licensed according to the terms in
 * the file LICENCE in the root of the source code directory.
 */
#include <QDebug>
#include <QWidget>
#include <QHBoxLayout>

#include "SAKGlobal.hh"
#include "SAKDataStruct.hh"
#include "SAKTcpClientDevice.hh"
#include "SAKTcpClientDebugPage.hh"
#include "SAKTcpClientDeviceController.hh"

SAKTcpClientDebugPage::SAKTcpClientDebugPage(QWidget *parent)
    :SAKDebugPage (SAKDataStruct::DebugPageTypeTCPClient, parent)
{
    tcpClientDeviceController = new SAKTcpClientDeviceController(this);
    initializingPage();
    setWindowTitle(SAKGlobal::debugPageNameFromType(SAKDataStruct::DebugPageTypeTCPClient));
}

SAKTcpClientDebugPage::~SAKTcpClientDebugPage()
{
    tcpClientDeviceController->deleteLater();
}

SAKTcpClientDeviceController *SAKTcpClientDebugPage::controllerInstance()
{
    return tcpClientDeviceController;
}

SAKDebugPageController *SAKTcpClientDebugPage::createController()
{
    return tcpClientDeviceController;
}

SAKDebugPageDevice *SAKTcpClientDebugPage::createDevice()
{
    SAKTcpClientDevice *device = new SAKTcpClientDevice(this);
    return device;
}
