from selenium import webdriver
from selenium.webdriver.common.by import By
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.chrome import service as ChromeService
import time

driver = webdriver.Chrome()

# Usando la calculadora
driver.get("https://www.calculator.net")

# Maximizando pantalla
driver.maximize_window()

# Clickeando en Math Calculators
driver.find_element(by=By.XPATH,value=".//*[@id = 'contentout']/table/tbody/tr/td[3]/div[2]/a").click()
# Clickeando en Porcentage calculator
driver.find_element(by=By.XPATH,value=".//*[@id='content']/table[2]/tbody/tr/td/div[3]/a").click()
# Ingresando porcentaje
driver.find_element(by=By.ID,value="cpar1").send_keys(10)
# Ingresando numero al cual se sacara un porcentaje
driver.find_element(by=By.ID,value= "cpar2").send_keys(50)
# Haciendo click en el boton Calculate
driver.find_element(by=By.XPATH,value=".//*[@id = 'content']/table/tbody/tr[2]/td/input[2]").click()

# Guardando el resultado
result = driver.find_element(by=By.XPATH,value=".//*[@id= 'content']/p[2]/font/b").text

# Imprimiendoen consola
print("The result is ", result)

# Haciendo que el programa espere 10 segundos antes de cerrar el navegador
time.sleep(10)

driver.quit()