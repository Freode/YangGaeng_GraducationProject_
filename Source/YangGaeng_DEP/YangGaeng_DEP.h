// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EngineMinimal.h"


DECLARE_LOG_CATEGORY_EXTERN(YangGaeng, Log, All);

#define YANGGAENG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))

#define YANGGAENG_SIMPLE(Verbosity) UE_LOG(YangGaeng, Verbosity, TEXT("%s"), *YANGGAENG_CALLINFO)

#define YANGGAENG_LOG(Verbosity, Format, ...) UE_LOG(YangGaeng, Verbosity, TEXT("%s %s"), *YANGGAENG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))
