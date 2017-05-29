import bb.cascades 1.2
import Network.LoginController 1.0

Page {
    signal done ()
        
    Container {
        id: rootContainer
        background: back.imagePaint
        layout: DockLayout {
        }
        
        Container {
            verticalAlignment: VerticalAlignment.Center    
            
            Label {
                id: label
                text: "HFR10"
                textStyle {
                    color: Color.Black
                    base: SystemDefaults.TextStyles.PrimaryText
                }
            }

            TextField {
                id: login
                hintText: qsTr("Login")
                textStyle {
                    color: Color.Black
                }
                backgroundVisible: false
            }
            
            TextField {
                id: password
                hintText: qsTr("Password")
                inputMode: TextFieldInputMode.Password
                backgroundVisible: false
                textStyle {
                    color: Color.Black
                }
                
            }
            
            Button {
                text: qsTr("Submit")
                horizontalAlignment: HorizontalAlignment.Center
                onClicked: {
                    if(login.text != "")
                        loginController.login(login.text,password.text);
                    else 
                        done();
                }
            }
        }
        
        attachedObjects: [
            ImagePaintDefinition {
                id: back
                repeatPattern: RepeatPattern.Fill
                
                
                imageSource: "asset:///images/wallpaper/wallpaper.jpg"
            }
        ]
    }
    
    attachedObjects: [
        LoginController {
            id: loginController
            
            onComplete: {
                done();
            }
        }
    ]
}
