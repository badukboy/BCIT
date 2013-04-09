jQuery(function()
            {
                jQuery("#id").validate(
                {
                    expression: "if (!isNaN(VAL) && VAL) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> ID must be a number.</p>"
                });
            
                jQuery("#vendorname").validate(
                {
                    expression: "if (!VAL.length == 0) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Vendor name cannot be blank.</p>"
                });
                
                jQuery("#surname").validate(
                {
                    expression: "if (!VAL.length == 0) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Surname cannot be blank.</p>"
                });
                
                jQuery("#firstname").validate(
                {
                    expression: "if (!VAL.length == 0) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> First name cannot be blank.</p>"
                });
                
                jQuery("#accountname").validate(
                {
                    expression: "if (!VAL.length == 0) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Account name cannot be blank.</p>"
                });
                
                jQuery("#productname").validate(
                {
                    expression: "if (!VAL.length == 0) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Product name cannot be blank.</p>"
                });
                
                jQuery("#quantityonhand").validate(
                {
                    expression: "if (!isNaN(VAL) && VAL) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Quantity on hand must be a number.</p>"
                });
                
                jQuery("#reorderpoint").validate(
                {
                    expression: "if (!isNaN(VAL) && VAL) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Reorder point must be a number.</p>"
                });
                
                jQuery("#reorderquantity").validate(
                {
                    expression: "if (!isNaN(VAL) && VAL) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Reorder quantity must be a number.</p>"
                });
                
                jQuery("#supplieraccountno").validate(
                {
                    expression: "if (!isNaN(VAL) && VAL) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Preferred supplier account must be a number.</p>"
                });
                
                jQuery("#customer").validate(
                {
                    expression: "if (!isNaN(VAL) && VAL) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Customer ID must be a number.</p>"
                });
                
                jQuery("#description").validate(
                {
                    expression: "if (!VAL.length == 0) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Description must not be blank.</p>"
                });
                
                jQuery("#datePicker").validate(
                {
                    expression: "if (!VAL.length == 0) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> You must pick valid date.</p>"
                });
                
                jQuery("#vendor").validate(
                {
                    expression: "if (!isNaN(VAL) && VAL) return true; else return false;",
                    message: "<p><i class='icon-exclamation-sign'></i> Vendor ID must be a number.</p>"
                });
            });