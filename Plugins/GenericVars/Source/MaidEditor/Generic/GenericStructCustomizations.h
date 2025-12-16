// Copyright Liquid Fish. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "IPropertyTypeCustomization.h"
#include "SGraphPin.h"
#include "IDetailPropertyRow.h"
#include "Generic/Generic.h"

class MAIDEDITOR_API FGenericStructCustomization : public IStructCustomization
{
public:
	static TSharedRef<IPropertyTypeCustomization> MakeInstance();
	virtual ~FGenericStructCustomization();

	virtual void CustomizeStructHeader(TSharedRef<IPropertyHandle> StructPropertyHandle, class FDetailWidgetRow& HeaderRow, IStructCustomizationUtils& StructCustomizationUtils) override;
	virtual void CustomizeStructChildren(TSharedRef<IPropertyHandle> StructPropertyHandle, class IDetailChildrenBuilder& ChildBuilder, IStructCustomizationUtils& StructCustomizationUtils) override;

	TWeakPtr<IPropertyHandle> PropertyHandle;
	IDetailChildrenBuilder* LastChildBuilder = nullptr;
	bool GetVariableTypeChangeEnabled() const;
	FEdGraphPinType OnGetVarType() const;
	void OnVarTypeChanged(const FEdGraphPinType& NewPinType);

private:
	void ForceRebuildDetails();
	void CreateChildrenInternal(IDetailChildrenBuilder& ChildBuilder);

	FDelegateHandle UndoHandle;
};
